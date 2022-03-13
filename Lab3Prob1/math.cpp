#define _CRT_SECURE_NO_WARNINGS
#include "math.h"
#include <stdarg.h> 
#include <stdlib.h>
#include <cstring>

int Math::Add(int x, int y)
{
    return x + y;
}

int Math::Add(int x, int y, int z)
{
    return x + y + z;
}

int Math::Add(double x, double y)
{
    return x + y;
}

int Math::Add(double x, double y, double z)
{
    return x + y + z;
}

int Math::Mul(int x, int y)
{
    return x * y;
}

int Math::Mul(int x, int y, int z)
{
    return x * y * z;
}

int Math::Mul(double x, double y)
{
    return x * y;
}

int Math::Mul(double x, double y, double z)
{
    return x * y *z;
}

int Math::Add(int count, ...)
{
    int val, sum = 0;
    va_list vl;
    va_start(vl, count);
    for (int i = 0; i < count; i++)
    {
        val = va_arg(vl, int);
        sum += val;
        
    }
    va_end(vl);

    return sum;
}

char* Math::Add(const char* string1, const char* string2)
{
    if(string1 == nullptr || string2 == nullptr) return nullptr;
    else {
        char* returnat = (char*)malloc(strlen(string1) + strlen(string2) + 1);
        if (returnat != nullptr)
        {
            strcpy(returnat, string1);
            strcat(returnat, string2);
        }
        return returnat;    
    }
}
