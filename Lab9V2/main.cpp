#include <iostream>
#include "Map.h"

int main()
{
    Map<int, const char*> m, M;
    const char* value;
    m[10] = "C++";
    m[20] = "test";
    m[30] = "Poo";

    m.Get(20, value);
    std::cout << value << std::endl;
    for (auto [key, value, index] : m)
    {
        printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
    }

    m[20] = "result";

    for (auto [key, value, index] : m)
    {
        printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
    }

    return 0;
}