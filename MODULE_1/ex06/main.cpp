#include "./includes/Harl.hpp"







int main(int argc, char **argv)
{
    if (argc != 2)
        return (1);
    Harl harlay;

    int res = harlay.complain(argv[1]);
    if (res == -1)
        std::cout << "Probably complaining about insignificant problem"
                  << std::endl;
}