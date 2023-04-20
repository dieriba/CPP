#include "./includes/RPN.hpp"


int main(int argc, char **argv)
{
    if (argc != 2) return 1;
    try
    {
        RPN::_calcul[('+' % 10)] = RPN::add;
        RPN::_calcul[('*' % 10)] = RPN::multiply;
        RPN::_calcul[('-' % 10)] = RPN::substract;
        RPN::_calcul[('/' % 10)] = RPN::divide;
        RPN a(argv[1]);
        a.makeStack();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
}