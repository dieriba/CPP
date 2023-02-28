#include "./includes/Convert.hpp"


int main (int argc, char **argv)
{
    if (argc != 2)
        return (1);
    Converter::convert(argv[1]);
}