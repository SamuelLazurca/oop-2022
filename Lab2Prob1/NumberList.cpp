#include<iostream>
#include "NumberList.h"

using std::cout;
using std::endl;

void NumberList::Init()
{
    this->count = 0;
}

bool NumberList::Add(int x)
{
    if (this->count < 10) {
        this->numbers[count] = x;
        this->count++;
        return true;
    }
    return false;
}

void NumberList::Sort()
{
    //bubblesort
    int index, aux, lastindex, last = this->count - 1;
    
    while (last > 0)
    {
        lastindex = last - 1;
        for (index = 0; index <= lastindex; index++)
        {
            last = 0;
            if (this->numbers[index] > this->numbers[index + 1])
            {
                aux = this->numbers[index];
                this->numbers[index] = this->numbers[index + 1];
                this->numbers[index + 1] = aux;
                last = index;
            }
        }
    }

}

void NumberList::Print()
{
    for (int index = 0; index < this->count; index++)
    {
        cout << this->numbers[index] << " ";
    }
    cout << endl;
}
