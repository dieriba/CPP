#include <cstdlib>
#include <iostream>

class test
{
    public:
        test(){};
        ~test(){};
        typedef int(*calcul)(int a,int b);
        /*STATIC METHOD*/
        static int add(int a, int b);
        static int divide(int a, int b);
        static int multiply(int a, int b);
        static int substract(int a, int b);
        static calcul _calcul[128];
    private:
        /* data */
};

/*----------------------------------STATIC MEMBER FUNCTION----------------------------------*/
int test::add(int a, int b){return a + b;};
int test::substract(int a, int b){return a - b;};
int test::multiply(int a, int b){return a * b;};
int test::divide(int a, int b)
{
    if (b == 0)
    {
        std::cerr << "Error\n";
        exit(1);
    }
    return a / b;
};
/*----------------------------------STATIC MEMBER FUNCTION----------------------------------*/

int main(void)
{
    test::_calcul['+'] = &test::add;
    test::_calcul['-'] = &test::substract;
    test::_calcul['/'] = &test::divide;
    test::_calcul['*'] = &test::multiply;
    test d;
}