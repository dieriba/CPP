#include "./includes/Array.h"
#include <string>





int main (void)
{
    Array<std::string> dieri(5);
    dieri[0] = "dieri";
    dieri[1] = "nabs";
    dieri[2] = "fanta";
    dieri[3] = "bala";
    dieri[4] = "go";

    Array<std::string> mams(dieri);    
    std::cout << mams;
}