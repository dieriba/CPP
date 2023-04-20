#include "./includes/RPN.hpp"

/*----------------------------------CONSTRUCTOR/DESTRUCTOR----------------------------------*/
RPN::RPN(){};
RPN::RPN(const std::string& arg):arg(arg){};
RPN::RPN(const RPN& rhs):arg(rhs.getArgs()){};
RPN& RPN::operator=(const RPN& rhs)
{
    if (this == &rhs) return (*this);
    arg = rhs.getArgs();
    return (*this);
}
RPN::~RPN(){};
/*----------------------------------CONSTRUCTOR/DESTRUCTOR----------------------------------*/
/*----------------------------------GETTER----------------------------------*/
const std::string& RPN::getArgs(void) const{return arg;}
/*----------------------------------GETTER----------------------------------*/

/*----------------------------------MEMBER FUNCTION----------------------------------*/
bool RPN::getTop(int& top)
{
    if (rpn.empty())
        return false;
    top = rpn.top();    
    return true;
}

void RPN::printErr(void)
{
    std::cerr << "Error" << std::endl;
    exit(1);
};

void RPN::makeStack(void)
{
    std::stringstream ss(arg);
    std::string s;
    int res = 0;
    int top;
    int tmp;
    char c;

    while (std::getline(ss, s, ' '))
    {
        if (s.find_first_not_of(RPN_BASE) != std::string::npos || s.length() > 1)
            printErr();
        if (s.size() > 0 && !isdigit(s.at(0)))
        {
            if (!getTop(tmp)) printErr();
            top = tmp;
            rpn.pop();
            if (!getTop(tmp)) printErr();
            res = tmp;
            rpn.pop();
            c = s.at(0);
            res = RPN::_calcul[c % 10](res, top);
            rpn.push(res);
        }
        else if (s.size() > 0)
            rpn.push(atoi(s.c_str()));
    }
    if (rpn.size()) rpn.pop();
    if (rpn.size())
        std::cerr << "Bad RPN Synatx" << std::endl;
    else
        std::cout << res << std::endl;
}
/*----------------------------------MEMBER FUNCTION----------------------------------*/
/*----------------------------------STATIC MEMBER FUNCTION----------------------------------*/
int RPN::add(int a, int b){return a + b;};
int RPN::substract(int a, int b){return a - b;};
int RPN::multiply(int a, int b){return a * b;};
int RPN::divide(int a, int b)
{
    if (b == 0)
        throw std::runtime_error("Error");
    return a / b;
};
/*----------------------------------STATIC MEMBER FUNCTION----------------------------------*/
RPN::calcul RPN::_calcul[10] = {0};