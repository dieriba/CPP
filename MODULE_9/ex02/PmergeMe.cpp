# include "./includes/PmergeMe.hpp"
# include <set>
# include <algorithm>
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
/*-------------------------------GETTER-------------------------------*/


/*-------------------------------MEMBER FUNCTION-------------------------------*/
void PmergeMe::addToContainers(const std::string& number)
{
    static std::set<int> _set;

    if (number.find_first_not_of(BASE) != std::string::npos) throw std::runtime_error("Error");
    int val;
    std::stringstream ss(number);

    ss >> val;
    if (ss.fail()) throw std::runtime_error("Error");
    _vec.push_back(val);
    _list.push_back(val);
    if (_set.insert(val).second == false)
        throw std::runtime_error("Error");
}

void PmergeMe::BeforeMerge(void) const
{
    std::cout << "Before: " << _vec;
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
    it_list middle = first;
    std::advance(middle, (std::distance(first, last) / 2));
    Pmerge(first, middle);
    Pmerge(middle, last);
    std::inplace_merge(first, middle, last);
}

void PmergeMe::PmergeContainers(void)
{
    Pmerge(_vec.begin(), _vec.end());
}
/*-------------------------------MEMBER FUNCTION-------------------------------*/