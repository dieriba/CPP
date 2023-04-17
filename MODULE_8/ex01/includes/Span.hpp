# include <vector>
# include <cstdlib>
# include <iostream>
# include <algorithm>
# include <numeric>

class Span
{
    public:
        Span();
        Span(unsigned int n);
        Span(const Span& rhs);
        Span& operator=(const Span& rhs);
        ~Span();

        unsigned int getSize(void) const;
        void fillArray(void);
        void addNumber(int n);
        int shortestSpan(void);
        int longestSpan(void);
    private:
        unsigned int size;
        std::vector<int> arr;
};