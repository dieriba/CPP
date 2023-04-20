#include "./includes/BitcoinExchange.hpp"




int main(int argc, char **argv)
{
    if (argc != 2) return 1;
    try
    {
        BitcoinExchange::setTree();
        BitcoinExchange binance(argv[1]);
        binance.printRate();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
}