#include "./includes/Base.hpp"
#include "./includes/A.hpp"
#include "./includes/B.hpp"
#include "./includes/C.hpp"
#include <cstdlib>
#include <stdexcept>

Base* genereate(void)
{
    int i = rand() % 3;
    if (i == 0)
        return new A;
    else if (i == 1)
        return new B;
    else
        return new C;
}

void identify(Base* p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "p: " << "\"A\"" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "p: " << "\"B\"" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "p: " << "\"C\"" << std::endl;
}

void identify(Base& p)
{
    try 
    {
        A &t = dynamic_cast<A&>(p);
        (void)t;
        std::cout << "p: " << "\"A\"" << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    };
    try 
    {
        B& t = dynamic_cast<B&>(p);
        (void)t;
        std::cout << "p: " << "\"B\"" << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    };
    try 
    {
        C& t = dynamic_cast<C&>(p);
        (void)t;
        std::cout << "p: " << "\"C\"" << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    };
}

int main ()
{
    Base* p;
  
    try
    {
        p = genereate();
        identify(p);
        identify(*p);
        delete p ;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        delete p;
    }
}