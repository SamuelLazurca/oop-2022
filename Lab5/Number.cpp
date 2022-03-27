#define _CRT_SECURE_NO_WARNINGS
#include "Number.h"
#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

#define A 10
#define B 11
#define C 12
#define D 13
#define E 14
#define F 15

int decimal(char* value, int base)
{
    int nr_decimal = 0;
    if (base != 10) {
        //switch to base 10 
        char copy[100];
        int len = strlen(value) - 1, c, pow = 1;

        strcpy(copy, value);
        while (len >= 0)
        {
            switch (copy[len]) {
            case 'A': c = 10; break;
            case 'B': c = 11; break;
            case 'C': c = 12; break;
            case 'D': c = 13; break;
            case 'E': c = 14; break;
            case 'F': c = 15; break;
            default: c = copy[len] - '0';
            }

            nr_decimal += c * pow;
            pow *= base;
            len--;
        }
    }
    else {
        //the number is in base 10
        char copy[100];
        int len = strlen(value) - 1, c, pow = 1;

        strcpy(copy, value);
        while (len >= 0)
        {
            c = copy[len] - '0';
            nr_decimal += c * pow;
            pow *= 10;
            len--;
        }
    }
    return nr_decimal;
}

Number::Number(const char* value, int base)
{
    this->base = base;
    this->value = new char [strlen(value) + 1];
    strcpy(this->value, value);
}

Number::Number(const Number& n)
{
    this->base = n.base;
    this->value = new char[strlen(n.value) + 1];
    strcpy(this->value, n.value);
}

Number::Number(Number&& n)
{
    this->value = n.value;
    this->base = n.base;  
    n.value = nullptr;
    n.base = 0;
}

Number::Number(int value)
{
    char val[100];
    _itoa(value, val, 10);
    this->base = 10;
    this->value = new char[strlen(val) + 1];
    strcpy(this->value, val);
}

Number::~Number()
{
    delete []this->value;
    this->base = 0;
}

bool Number::operator>(Number& n2)
{
    if (decimal(this->value, this->base) > decimal(n2.value, n2.base)) return true; 
    return false;
}

bool Number::operator<(Number& n2)
{
    if (decimal(this->value, this->base) < decimal(n2.value, n2.base)) return true;
    return false;
}

bool Number::operator>=(Number& n2)
{
    return !(*this < n2);
}

bool Number::operator<=(Number& n2)
{
    return !(*this > n2);
}

char* add_strings(const char* Number1, const char* Number2)
{
    int Length1 = strlen(Number1);
    int Length2 = strlen(Number2);
    int carry = 0;
    int k = 0;
    int i = Length1 - 1;
    int j = Length2 - 1;
    char* sum = new char[100];

    for (; i >= 0 && j >= 0; i--, j--, k++)
    {
        sum[k] = (Number1[i] - '0' + Number2[j] - '0' + carry) % 10 + '0';
        carry = (Number1[i] - '0' + Number2[j] - '0' + carry) / 10;
    }

    if (Length1 > Length2)
    {
        while (i >= 0) {
            sum[k++] = ((Number1[i] - '0' + carry) % 10) + '0'; 
            carry = ((Number1[i--] - '0' + carry) / 10);
        }
    }
    else if (Length1 < Length2)
    {
        while (j >= 0) {
            
            sum[k++] = ((Number2[j] - '0' + carry) % 10) + '0';
            carry = ((Number2[j--] - '0' + carry) / 10);
        }
    }
    else
    {
        if (carry > 0)
            sum[k++] = carry + '0';
    }
    sum[k] = '\0';
    strcpy(sum,_strrev(sum));
    return sum;
}

bool Number::operator==(Number& n2)
{
    return !(*this < n2) && !(*this > n2);
}

bool Number::operator!=(Number& n2)
{
    return !(*this == n2);
}

Number& Number::operator=(Number n)
{
    delete[] this->value;
    this->value = new char[strlen(n.value) + 1];
    strcpy(this->value, n.value);
    this->base = n.base;
    return *this;
}

Number& Number::operator=(int value)
{
    char val[100];
    _itoa(value, val, this->base);
    delete[] this->value;
    this->value = new char[strlen(val) + 1];
    strcpy(this->value, val);
    return *this;
}

Number& Number::operator=(const char* value)
{
    this->value = new char[strlen(value) + 1];
    strcpy(this->value, value);
    this->SwitchBase(this->base);
    return *this;
}

Number& Number::operator+=(Number n)
{
    strcpy(this->value, add_strings(this->value, n.value));
    return *this;
}

Number& Number::operator--()
{
    strcpy(this->value, this->value + 1);
    return *this;
}

Number& Number::operator--(int)
{
    this->value[this->GetDigitsCount() - 1] = '\0';
    return *this;
}

char Number::operator[](int index)
{
    if(index < this->GetDigitsCount()) return this->value[index];
    return 0;
}

void Number::SwitchBase(int newBase)
{
    int nr_decimal = decimal(this->value, this->base);
    
    char result[100];
    int index = 0;
    if (nr_decimal == 0) { strcpy(result, "0"); index++; }
    else {
        while (nr_decimal)
        {
            int c = nr_decimal % newBase;
            nr_decimal /= newBase;

            switch (c) {
            case A: result[index] = 'A'; break;
            case B: result[index] = 'B'; break;
            case C: result[index] = 'C'; break;
            case D: result[index] = 'D'; break;
            case E: result[index] = 'E'; break;
            case F: result[index] = 'F'; break;
            default: result[index] = '0' + c;
            }
            index++;
        }
    }
    result[index] = '\0';
    strcpy(result, _strrev(result));
    
    delete[] this->value;
    this->value = new char[index + 1];
    strcpy(this->value, result);
    this->base = newBase;
}

void Number::Print()
{
    printf("Value = %s   Base = %d \n", this->value, this->base);
}

int Number::GetDigitsCount()
{
    return strlen(this->value);
}

int Number::GetBase()
{
    return this->base;
}

Number operator+(Number n1, Number n2)
{
    int b1 = n1.base;
    int b2 = n2.base;
    if (b1 > b2)
    {
        n1.SwitchBase(10);
        n2.SwitchBase(10);
        char* result = add_strings(n1.value, n2.value);
        n1.SwitchBase(b1);
        n2.SwitchBase(b2);
        
        Number res(result, 10);
        res.SwitchBase(b1);
        return res;
    }
    else if (b1 < b2)
    {
        n1.SwitchBase(10);
        n2.SwitchBase(10);
        char* result = add_strings(n1.value, n2.value);
        n1.SwitchBase(b1);
        n2.SwitchBase(b2);
       
        Number res(result, 10);
        res.SwitchBase(b1);
        return res;
    }
    else
    {
        n1.SwitchBase(10);
        n2.SwitchBase(10);
        char* result = add_strings(n1.value, n2.value);
        n1.SwitchBase(b1);
        n2.SwitchBase(b2);
        
        Number res(result, 10);
        res.SwitchBase(b1);
        return res;
    }
}

Number operator-(Number n1, Number n2)
{
    if (n1 > n2) {
        char result[100];
        _itoa(decimal(n1.value, n1.base) - decimal(n2.value, n2.base), result, 10);
        int base = n1.base > n2.base ? n1.base : n2.base;

        Number res(result, 10);
        res.SwitchBase(base);
        return res;
    }
    else return { "0",10 };
}
