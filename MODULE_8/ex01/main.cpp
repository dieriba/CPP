#include "./includes/Span.hpp"
int main()
{
    // Span sp = Span(5);

    // int arr[] = {6,3,17,9,11};
    // std::vector<int> vector(arr, arr + 5);
    
    // sp.fillArray(vector.begin(), vector.end());
    // try
    // {
    //     std::cout << sp.shortestSpan() << std::endl;
    // }
    // catch(const std::exception& e)
    // {
    //     std::cerr << e.what() << '\n';
    // }
    
    // try
    // {
    //     std::cout << sp.longestSpan() << std::endl;
    // }
    // catch(const std::exception& e)
    // {
    //     std::cerr << e.what() << '\n';
    // }
    {
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }
    return 0;
}