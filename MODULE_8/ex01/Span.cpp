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

Span::Span(const Span& rhs):size(rhs.getSize()),arr(rhs.arr)
{
    size = rhs.getSize();
    arr = rhs.arr;
}

Span& Span::operator=(const Span& rhs)
{
    if (this == &rhs)
        return *this;
    size = rhs.getSize();
    arr = rhs.arr;
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
    int tmp = -1;
    std::vector<int> _vec = arr;
    std::sort(_vec.begin(), _vec.end());
 
    for(size_t i = 0; i < _vec.size() - 1; i++)
    {
        if (tmp == -1)
            tmp = _vec[i + 1] - _vec[i];
        else if (tmp > _vec[i + 1] - _vec[i])
            tmp = _vec[i + 1] - _vec[i];
    }
    return tmp;
}

int Span::longestSpan(void)
{
    if (arr.empty() || arr.size() == 1)
        throw std::runtime_error("No span found");
    int min = *std::min_element(arr.begin(), arr.end());
    int max = *std::max_element(arr.begin(), arr.end());
    return max - min;
}




void Span::fillArray(it_vec it, it_vec end)
{
    for (; it != end; it++)
        arr.push_back(*it);
    std::cout << arr << std::endl;
}
/*----------------------------------------MEMBER/FUNCTION-----------------------------------------*/
