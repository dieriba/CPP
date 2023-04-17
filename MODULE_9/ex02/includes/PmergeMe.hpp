# ifndef __PMERGEME_HPP__
# define __PMERGEME_HPP__

# include <vector>
# include <list>
# include <string>
# include <iostream>
# include <sstream>

# define BASE "0123456789"

typedef std::vector<int>::iterator it_vec;
typedef std::list<int>::iterator it_list;

class PmergeMe
{
    public:
        PmergeMe();
        PmergeMe(const PmergeMe& rhs);
        PmergeMe& operator=(const PmergeMe& rhs);
        ~PmergeMe();


        /*GETTERS*/
        const std::vector<int>& getVector(void) const;
        const std::list<int>& getList(void) const;
        /*SETTERS*/
        void    addToContainers(const std::string& number);

        /*MEMBER FUNCTION*/
        void BeforeMerge(void) const;
        void TimeTakenForVector(void) const;
        void TimeTakenForList(void) const;
        void Pmerge(it_vec first, it_vec last);
        void Pmerge(it_list first, it_list last);
        void PmergeContainers(void);

    private:
        std::vector<int> _vec;
        std::list<int> _list;
};

template < class T >
std::ostream& operator << (std::ostream& os, const std::vector<T>& vec) 
{
    if (vec.size() > 4)
    {
        for (size_t i = 0; i < 4; i++)
            os << vec[i] << " ";        

        os << "[...]";
    }
    else
    {
        for (size_t i = 0; i < vec.size(); i++)
            os << vec[i] << " ";        
    }
    os << std::endl;
    return os;
}

# endif