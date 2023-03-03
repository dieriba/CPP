#ifndef __INTER_HPP_
#define __INTER_HPP_
#include <iostream>
template<typename T>
void func(T &val)
{
    std::cout << "value is: " << val << std::endl;
};

template<typename T>
void iter(T *arr, int length, void(*func)(T &val))
{
    int i = -1;
    while (++i < length)
        func(arr[i]);
};

#endif