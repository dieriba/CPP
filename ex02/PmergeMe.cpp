# include "./includes/PmergeMe.hpp"
# include <set>
# include <algorithm>
# include <ctime>
# include <iomanip>
/*-------------------------------CONSTRUCTOR/DESTRUCTOR-------------------------------*/
PmergeMe::PmergeMe(){};
PmergeMe::PmergeMe(const PmergeMe& rhs):_vec(rhs._vec),_list(rhs._list){}
PmergeMe& PmergeMe::operator=(const PmergeMe& rhs)
{
    _vec = rhs._vec;
    _list = rhs._list;
    return *this;
}
PmergeMe::~PmergeMe(){};
/*-------------------------------CONSTRUCTOR/DESTRUCTOR-------------------------------*/

/*-------------------------------GETTER-------------------------------*/
const std::vector<int>& PmergeMe::getVector(void) const {return _vec;};
const std::list<int>& PmergeMe::getList(void) const {return _list;};
const std::clock_t& PmergeMe::getBeginVecTime(void) const {return _begin_vec;}
const std::clock_t& PmergeMe::getBeginListTime(void) const {return _begin_list;}
const std::clock_t& PmergeMe::getEndVecTime(void) const {return _end_vec;}
const std::clock_t& PmergeMe::getEndListTime(void) const {return _end_list;}
/*-------------------------------GETTER-------------------------------*/


/*-------------------------------SETTER-------------------------------*/
void    PmergeMe::setBeginVecTime(void)
{
    _begin_vec = std::clock();
}

void    PmergeMe::setBeginListTime(void)
{
    _begin_list = std::clock();
}

void    PmergeMe::setEndVecTime(void)
{
    _end_vec = std::clock();
}

void    PmergeMe::setEndListTime(void)
{
    _end_list = std::clock();
}
/*-------------------------------SETTER-------------------------------*/


/*-------------------------------MEMBER FUNCTION-------------------------------*/
void PmergeMe::addToVector(const std::string& number)
{
    static std::set<int> _set;

    if (number.find_first_not_of(BASE) != std::string::npos) throw std::runtime_error("Error");
    int val;
    std::stringstream ss(number);

    ss >> val;
    if (ss.fail()) throw std::runtime_error("Error");
    _vec.push_back(val);
    if (_set.insert(val).second == false)
        throw std::runtime_error("Error");
}

void PmergeMe::Pmerge(it_vec first, it_vec last)
{
    if (last - first > 1)
    {
        it_vec middle = first + (last - first) / 2;
        Pmerge(first, middle);
        Pmerge(middle, last);
        std::inplace_merge(first, middle, last);
    }
}

void PmergeMe::Pmerge(it_list first, it_list last)
{
    if (std::distance(first, last) <= 1)
        return ;
    it_list middle = first;
    std::advance(middle, (std::distance(first, last) / 2));
    Pmerge(first, middle);
    Pmerge(middle, last);
    std::inplace_merge(first, middle, last);
}

void PmergeMe::PmergeContainers(void)
{
    std::vector<int> vec_cp(_vec);
    Pmerge(_vec.begin(), _vec.end());
    setEndVecTime();
    setBeginListTime();
    for (const_it_vec it = vec_cp.begin(); it != vec_cp.end(); it++)
        _list.push_back(*(it));
    Pmerge(_list.begin(), _list.end());
    setEndListTime();
    std::cout << "Before: " << vec_cp;
    std::cout << "After: " << _vec;
    std::cout << std::fixed << std::setprecision(3) << "Time to process a range of " << _vec.size() << " elements with std::vector : " << 1000.0 * (_end_vec - _begin_vec) / CLOCKS_PER_SEC << " ms" << std::endl;
    std::cout << std::fixed << std::setprecision(3) << "Time to process a range of " << _list.size() << " elements with std::list : " << 1000.0 * (_end_list - _begin_list) / CLOCKS_PER_SEC << " ms" << std::endl;
}
/*-------------------------------MEMBER FUNCTION-------------------------------*/