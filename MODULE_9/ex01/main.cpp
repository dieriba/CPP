#include "./includes/RPN.hpp"


int main(int argc, char **argv)
{
    RPN::_calcul[('+' % 10)] = RPN::add;
    RPN::_calcul[('*' % 10)] = RPN::multiply;
    RPN::_calcul[('-' % 10)] = RPN::substract;
    RPN::_calcul[('/' % 10)] = RPN::divide;
    if (argc != 2) return 1;
    RPN a(argv[1]);
    a.makeStack();
}