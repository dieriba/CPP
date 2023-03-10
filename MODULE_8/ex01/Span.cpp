#include "./includes/Span.hpp"

/*----------------------------------------CONSTRUCTOR/DESTRUCTOR-----------------------------------------*/
Span::Span()
{
    size = 5;
    arr.reserve(size);
}

Span::Span(unsigned int n)
{
    size = n;
    arr.reserve(n);
}

Span::Span(const Span& rhs)
{
    size = rhs.getSize();
    arr.reserve(size);
    for (unsigned int i = 0; i < size; i++)
        arr[i] = rhs.arr.at(i);    
}

Span& Span::operator=(const Span& rhs)
{
    if (this == &rhs)
        return *this;
    size = rhs.getSize();
    arr.reserve(size);
    for (unsigned int i = 0; i < size; i++)
        arr[i] = rhs.arr.at(i);
    return *this; 
}

Span::~Span(){};
/*----------------------------------------CONSTRUCTOR/DESTRUCTOR*----------------------------------------*/


/*----------------------------------------MEMBER/FUNCTION-----------------------------------------*/
unsigned int Span::getSize(void) const
{
    return size;
}

void Span::addNumber(int n)
{
    if (arr.size() == size)
        throw std::runtime_error("Array is full");
    arr.push_back(n);
}

int Span::shortestSpan(void)
{
    if (arr.empty() || arr.size() == 1)
        throw std::runtime_error("No span found");
    int shortSpan = abs(arr.at(0) - arr.at(1));
    int to_store;
    for (std::size_t i = 0; i < size - 1; i++)
    {
        for (std::size_t j = i + 1; j < size; j++)
        {
            to_store = abs(arr.at(i) - arr.at(j));
            if (to_store < shortSpan)
                shortSpan = to_store;
        }
    }
    return shortSpan;
}

int Span::longestSpan(void)
{
    if (arr.empty() || arr.size() == 1)
        throw std::runtime_error("No span found");
    int min = *std::min_element(arr.begin(), arr.end());
    int max = *std::max_element(arr.begin(), arr.end());
    return max - min;
}

void Span::fillArray()
{
    for (size_t i = 0; i < size; i++)
    {
        arr.push_back(i);
    }
    
}
/*----------------------------------------MEMBER/FUNCTION-----------------------------------------*/
