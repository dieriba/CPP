#include "./includes/BitcoinExchange.hpp"

/*---------------------------CONSTRUCTOR/DESTRUCTOR---------------------------*/
BitcoinExchange::BitcoinExchange():_filename("no_file"){};
BitcoinExchange::BitcoinExchange(const std::string& filename):_filename(filename)
{

};
BitcoinExchange::BitcoinExchange(const BitcoinExchange& rhs):_filename(rhs.getFilename()){};
BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& rhs)
{
    if (this == &rhs) return *this;
    _filename = rhs.getFilename();
    return *this;
};
BitcoinExchange::~BitcoinExchange(){};
/*---------------------------CONSTRUCTOR/DESTRUCTOR---------------------------*/

/*---------------------------MEMBER/FUNCTION---------------------------*/
const std::string& BitcoinExchange::getFilename(void) const {return _filename;};

bool BitcoinExchange::checkValidDateFormat(std::string& date) const
{
    size_t i = 0;
    size_t len = i;
    std::string sub;
    int d_m;

    if (date.size() != 11) return false ;
    date.resize(10);
    for (; i < 4; i++) if (!isdigit(date[i])) return false ;
    if (date[i++] != '-') return false ;
    for (len = i + 2; i != len; i++) if (!isdigit(date[i])) return false ;
    d_m = atoi(date.substr(i - 2, i).c_str());
    if (d_m < 0 || d_m > 31) return false ;
    if (date[i++] != '-') return false ;
    for (len = i + 2; i != len; i++) if (!isdigit(date[i])) return false ;
    d_m = atoi(date.substr(i - 2, i).c_str());
    if (d_m < 0 || d_m > 31) return false ;
    return true ;
}

void BitcoinExchange::findValueOfBitcoin(const std::string& date, double& value) const
{
    std::map<std::string, double>::iterator it = BitcoinExchange::_tree.begin();
    std::map<std::string, double>::iterator end = BitcoinExchange::_tree.end();
    std::map<std::string, double>::const_iterator found = BitcoinExchange::_tree.find(date);
    std::map<std::string, double>::const_iterator begin = BitcoinExchange::_tree.begin();

    if (found != _tree.end())
        value = found -> second;
    else
    {
        if (date < begin -> first)
            value = begin -> second;
        else
        {
            it++;
            for (; it != end; it++)
            {
                if (it -> first > date)
                {
                    --it;
                    break ;
                }
            }
            value = ((it == end) ? --end -> second : it -> second);
        }
    }

}

void BitcoinExchange::clearAndPrint(std::string& line) const
{
    std::string s;
    std::string s1;
    std::stringstream stream(line);
    double value = 0;
    double base_val;
    int lims;

    std::getline(stream, s, '|');
    std::getline(stream, s1);
    if (!checkValidDateFormat(s))
        printErr("bad input => " + s);
    else
    {
        findValueOfBitcoin(s, value);
        if (!std::isspace(s1.at(0)) || s1.find_first_not_of(BASE, 1) != std::string::npos || s1.size() <= 1)
            printErr("bad input => " + s1);
        else
        {
            std::stringstream ss(s1);
            s1.erase(0, 1);
            ss >> lims;
            if (ss.fail())
                printErr("too large a number");
            else if (lims < 0)
                printErr("not a positive number.");
            else
            {
                std::stringstream ss1(s1);
                ss1 >> base_val;
                value *= base_val;
                std::cout << s << " => " << s1 << " = " << value << std::endl;
            }
        }
    }
}

void BitcoinExchange::printRate(void) const
{
    std::string s;
    std::ifstream file(_filename.c_str());
    if (!file)
    {
        std::cerr << "Error: could not open file." << std::endl;
        exit(1);
    }
    std::getline(file, s);
    while (std::getline(file, s))
        clearAndPrint(s);
}

/*---------------------------MEMBER/FUNCTION---------------------------*/

/*---------------------------STATIC MEMBER/FUNCTION---------------------------*/

void BitcoinExchange::printErr(const std::string& err)
{
    std::cerr << "Error: " << err << std::endl;
}

void BitcoinExchange::fillTree(const std::string& line)
{
    std::stringstream stream(line);
    std::string s;
    std::string s1;
    std::getline(stream, s, ',');
    std::getline(stream, s1);
    BitcoinExchange::_tree[s] = strtold(s1.c_str(), NULL);
}

void BitcoinExchange::setTree(void)
{
    std::ifstream data("data.csv");
    std::string s;
    if (!data)
    {
        std::cerr << "Error: could not open file." << std::endl;
        exit(1);
    }
    std::getline(data, s);
    while (std::getline(data, s))
        fillTree(s);
    /*std::map<std::string, double>::iterator beg = _tree.begin();
    std::map<std::string, double>::iterator end = _tree.end();
    while (beg != end)
    {
        std::cout << beg -> first;
        std::cout << " " << beg -> second << std::endl;
        beg++;
    }*/
}
/*---------------------------STATIC MEMBER/FUNCTION---------------------------*/
std::map<std::string,double> BitcoinExchange::_tree;