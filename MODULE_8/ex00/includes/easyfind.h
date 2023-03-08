#ifndef __EASY_FIND_H__
#define __EASY_FIND_H__
#include <vector>
#include <list>
#include <algorithm>
#include <iostream>
template<template <typename> class T>
typename T<int>::iterator easyfind(T<int> &container, int to_find)
{
    return std::find(container.begin(), container.end(), to_find);
}
template<template <typename,typename> class T, typename Alloc>
typename T<int, Alloc>::iterator easyfind(T<int, Alloc> &container, int to_find)
{
    return std::find(container.begin(), container.end(), to_find);    
}
#endif