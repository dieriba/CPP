#include "./includes/MutantStack.hpp"
#include <iostream>




int main()
{
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    //[...]
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
    std::cout << *it << std::endl;
    ++it;
    }
    MutantStack<int> s(mstack);
    
    std::cout << std::endl;

    
    MutantStack<int>::iterator its = s.begin();
    MutantStack<int>::iterator ites = s.end();
    ++its;
    --its;
    while (its != ites)
    {
        std::cout << *its << std::endl;
        ++its;
    }
    return 0;
}