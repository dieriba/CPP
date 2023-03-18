#include "./includes/BitcoinExchange.hpp"




int main(int argc, char **argv)
{
    BitcoinExchange::setTree();
    if (argc != 2) return 1;
    BitcoinExchange binance(argv[1]);
    binance.printRate();
}