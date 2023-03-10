#include <stack>
#include <deque>
template <typename T>
class MutantStack : public std::stack<T>
{
    public:
        MutantStack(){};
        MutantStack(const MutantStack& rhs);
        MutantStack& operator=(const MutantStack& rhs);        
        ~MutantStack(){};
        typedef typename std::stack<T>::container_type::iterator iterator;
        typedef typename std::stack<T>::container_type::const_iterator const_iterator;
        iterator begin(void){return this -> c.begin();}
        iterator end(void){return this -> c.end();}
        const iterator cbegin(void){return this -> c.begin();}
        const iterator cend(void){return this -> c.end();}
};

template<typename T>
MutantStack<T>& MutantStack<T>::operator=(const MutantStack<T>& rhs){return *this;}
template<typename T>
MutantStack<T>::MutantStack(const MutantStack<T>& rhs):std::stack<T>(){(void)rhs;}