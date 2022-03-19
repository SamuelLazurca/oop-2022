#define _CRT_SECURE_NO_WARNINGS

#include "Sort.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <stdarg.h>  
#include <cstring>
#include <initializer_list>

using std::cout;
using std::cin;
using std::endl;

void swap(int& a, int& b)
{
    int aux;
    aux = a;
    a = b;
    b = aux;
}

Sort::Sort(int nr, int min, int max)
{
    srand(time(0));
    count = nr;
    for (int index = 0; index < count; index++)
    {
        v[index] = min + rand() % (max-min);
    }
}

Sort::Sort(int vector[], int n)
{
    count = n;
    for (int index = 0; index < count; index++)
    {
        v[index] = vector[index];
    }
}

Sort::Sort(int count, ...)
{
    this->count = count;
    va_list vl;
    va_start(vl, count);

    for (unsigned index = 0; index < count; index++)
    {
        v[index] = va_arg(vl, int);
    }

    va_end(vl);
}

Sort::Sort(const char* string)
{
    char copie[200];
    strcpy(copie, string);
    char* p;
    int index = 0;

    p = strtok(copie, ",");
    while (p != nullptr)
    {
        v[index] = atoi(p);
        index++;
        p = strtok(NULL, ",");
    }

    count = index;
}

Sort::Sort(std::initializer_list<int> l)
{
    int* iterator = (int*)l.begin();
    int i = 0;
    while (iterator < l.end())
    {
        this->v[i] = *iterator;
        iterator++;
        i++;
    }
    count = i;
}

void Sort::InsertSort(bool ascendent)
{
    int i, j, temp;

    if (ascendent == false)
    {
        for (i = 0; i < count; i++)
        {
            j = i - 1;
            temp = v[i];
            while (j >= 0 && v[j] < temp)
            {
                v[j + 1] = v[j];
                j = j - 1;
            }
            v[j + 1] = temp;
        }
        return;
    }
    for (i = 0; i < count; i++)
    {
        j = i - 1;
        temp = v[i];
        while (j >= 0 && v[j] > temp)
        {
            v[j + 1] = v[j];
            j = j - 1;
        }
        v[j + 1] = temp;
    }
}

void partitionare(int v[], int p, int q, int& k, bool ascendent)
{
    int x, i, j;
    x = v[p];
    i = p + 1;
    j = q;

    if (ascendent == false)
    {
        while (i <= j)
        {
            if (v[i] >= x) i++;
            if (v[j] <= x) j--;
            if (i < j && v[i] < x && x < v[j])
            {
                swap(v[i], v[j]);
                i++;
                j--;
            }
        }
        k = i - 1;
        v[p] = v[k];
        v[k] = x;
        return;
    }
    while (i <= j)
    {
        if (v[i] <= x) i++;
        if (v[j] >= x) j--;
        if (i<j && v[i]>x && x > v[j])
        {
            swap(v[i], v[j]);
            i++;
            j--;
        }
    }
    k = i - 1;
    v[p] = v[k];
    v[k] = x;
}

void quickSort(int v[], int p, int q, bool ascendent)
{
    int k;
    if (p < q)
    {
        partitionare(v, p, q, k,ascendent);
        quickSort(v, p, k - 1,ascendent);
        quickSort(v, k + 1, q,ascendent);
    }
}

void Sort::QuickSort(bool ascendent)
{
    quickSort(v, 0, count - 1, ascendent);
}

void Sort::BubbleSort(bool ascendent)
{
    int ultim, n1, i;
    ultim = count - 1;

    if (ascendent == false)
    {
        while (ultim > 0)
        {
            n1 = ultim - 1;
            ultim = 0;
            for (i = 0; i <= n1; i++)
                if (v[i] < v[i + 1])
                {
                    swap(v[i], v[i + 1]);
                    ultim = i;
                }
        }
        return;
    }
    while (ultim > 0)
    {
        n1 = ultim - 1;
        ultim = 0;
        for (i = 0; i <= n1; i++)
            if (v[i] > v[i + 1])
            {
                swap(v[i], v[i + 1]);
                ultim = i;
            }
    }
}

void Sort::Print()
{
    for (int index = 0; index < count; index++)
        cout << v[index] << " ";
    cout << endl;
}

int Sort::GetElementsCount()
{
    return count;
}

int Sort::GetElementFromIndex(int index)
{
    if (index >= 0 && index < count) return v[index];
    return -1;
}
