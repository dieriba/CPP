# ifndef __SPAN_HPP__
# define __SPAN_HPP__

# include <vector>
# include <cstdlib>
# include <iostream>
# include <algorithm>
# include <numeric>


typedef std::vector<int>::iterator it_vec;

class Span
{
    public:
        Span();
        Span(unsigned int n);
        Span(const Span& rhs);
        Span& operator=(const Span& rhs);
        ~Span();

        struct c_unique 
        {
            int current;
            c_unique() {current=0;}
            int operator()() {return ++current;}
        } UniqueNumber;

        unsigned int getSize(void) const;
        void fillArray(it_vec it, it_vec end);
        void addNumber(int n);
        int shortestSpan(void);
        int longestSpan(void);
    private:
        unsigned int size;
        std::vector<int> arr;
};

template <class T>
std::ostream& operator << (std::ostream& os, const std::vector<T>& v) 
{
    os << "[";
    for (typename std::vector<T>::const_iterator ii = v.begin(); ii != v.end(); ++ii)
    {
        os << " " << *ii;
    }
    os << "]";
    return os;
}
# endif