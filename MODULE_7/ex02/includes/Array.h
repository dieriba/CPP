#ifndef __ARRAY_H__
#define __ARRAY_H__
#include <iostream>
#include <stdexcept>
template<typename T>
class Array
{
    public:
        Array();
        Array(unsigned int n);
        Array(const Array& rhs);
        Array& operator=(const Array& rhs);
        ~Array();
        size_t getSize(void) const;
        T& getValue(size_t pos) const;
        T& operator[](size_t pos) const;
    private:
        T *arr;
        size_t lenght;
};

template<typename T>
std::ostream& operator<<(std::ostream& os, const Array<T>& arr)
{
    size_t  i = -1;
    while (++i < arr.getSize())
        os << "Index[" << i << "]: " << arr[i] << std::endl;
    return os;
}

template<typename T>
Array<T>::Array()
{
    arr = new T[5];
    lenght = 5;
};

template<typename T>
Array<T>::Array(unsigned int n)
{
    size_t i = -1;
    arr = new T[n];
    lenght = n;
    while (++i < n)
        arr[i] = T();
};

template<typename T>
Array<T>::~Array(){delete [] arr;};

template<typename T>
size_t Array<T>::getSize(void) const {return lenght;}

template<typename T>
T& Array<T>::operator[](size_t pos) const
{
    if (pos >= lenght) throw std::out_of_range("Ouf of array range");
    return arr[pos];
}

template<typename T>
T& Array<T>::getValue(size_t pos) const {return arr[pos];};

template<typename T>
Array<T>::Array(const Array& rhs)
{
    size_t i = -1;
    lenght = rhs.getSize();
    arr = new T[lenght];
    while (++i < lenght)
        arr[i] = rhs.getValue(i);
}

template<typename T>
Array<T>& Array<T>::operator=(const Array<T>& rhs)
{
    if (this == &rhs)
        return (*this);
    size_t i = -1;
    lenght = rhs.getSize();
    arr = new T[lenght];
    while (++i < lenght)
        arr[i] = rhs.getValue(i);
    return (*this);
}
#endif