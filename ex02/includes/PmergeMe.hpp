# ifndef __PMERGEME_HPP__
# define __PMERGEME_HPP__

# include <vector>
# include <list>
# include <string>
# include <iostream>
# include <sstream>
# include <vector>
# include <time.h>
# include <ctime>
# define BASE "0123456789"

typedef std::vector<int>::iterator it_vec;
typedef std::vector<int>::const_iterator const_it_vec;
typedef std::list<int>::iterator it_list;
typedef std::list<int>::const_iterator const_it_list;

class PmergeMe
{
    public:
        PmergeMe();
        PmergeMe(const PmergeMe& rhs);
        PmergeMe& operator=(const PmergeMe& rhs);
        ~PmergeMe();


        /*GETTERS*/
        const std::vector<int>& getVector(void) const;
        const std::list<int>&   getList(void) const;
        const std::clock_t&     getBeginVecTime(void) const;
        const std::clock_t&     getBeginListTime(void) const;
        const std::clock_t&     getEndVecTime(void) const;
        const std::clock_t&     getEndListTime(void) const;
        
        /*SETTERS*/
        void    addToVector(const std::string& number);
        void    setBeginVecTime(void);
        void    setBeginListTime(void);
        void    setEndVecTime(void);
        void    setEndListTime(void);

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
        std::clock_t _begin_vec;
        std::clock_t _begin_list;
        std::clock_t _end_vec;
        std::clock_t _end_list;
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

template < class T >
std::ostream& operator << (std::ostream& os,  const std::list<T>& list) 
{
    typename std::list<T>::const_iterator it = list.begin();
    typename std::list<T>::const_iterator end = list.end();
    int i = 0;
    if (list.size() > 4)
    {
        while (i < 4)
        {
            os << *(it) << " ";
            it++;
            i++;
        }
        os << "[...]";
    }
    else
    {
        for (; it != end; it++)
            os << *it << " ";        
    }
    os << std::endl;
    return os;
}

# endif