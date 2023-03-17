#include <stack>
#include <string>
#include <sstream>
#include <cstdlib>
#include <iostream>

#define RPN_BASE "0123456789*/+-"

class RPN
{
    public:
        RPN();
        RPN(const std::string& rpn);
        RPN(const RPN& rhs);
        RPN& operator=(const RPN&rhs);
        ~RPN();

        /*GETTER*/
        const std::string& getArgs(void) const;

        /*MEMBER FUNC*/
        void makeStack();
        bool getTop(int& top);
        void printErr(void);

        typedef int(*calcul)(int a,int b);
        /*STATIC METHOD*/
        static int add(int a, int b);
        static int divide(int a, int b);
        static int multiply(int a, int b);
        static int substract(int a, int b);
        static calcul _calcul[10];
        private:
            std::stack<int> rpn;
            std::string arg;
};

