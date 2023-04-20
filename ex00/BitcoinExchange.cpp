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

bool BitcoinExchange::checkValidDateFormat(std::string& date, const size_t& len_)
{
    size_t i = 0;
    size_t len = i;
    std::string sub;
    int d_m;

    if (date.size() != len_) return false ;
    date.resize(10);
    for (; i < 4; i++) if (!isdigit(date[i])) return false ;
    if (date[i++] != '-') return false ;
    for (len = i + 2; i != len; i++) if (!isdigit(date[i])) return false ;
    d_m = atoi(date.substr(i - 2, i).c_str());
    if (d_m < 1 || d_m > 31) return false ;
    if (date[i++] != '-') return false ;
    for (len = i + 2; i != len; i++) if (!isdigit(date[i])) return false ;
    d_m = atoi(date.substr(i - 2, i).c_str());
    if (d_m < 1 || d_m > 31) return false ;
    return true ;
}

bool BitcoinExchange::findValueOfBitcoin(const std::string& date, double& value) const
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
            return false;
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
            value = ((it == end) ? (--it) -> second : it -> second);
        }
    }
    return true;
}

void BitcoinExchange::clearAndPrint(std::string& line) const
{
    std::string s;
    std::string s1;
    std::stringstream stream(line);
    std::stringstream ss;
    double value = 0;
    long double base_val;

    std::getline(stream, s, '|');
    std::getline(stream, s1);
    if (!BitcoinExchange::checkValidDateFormat(s, 11))
        printErr("bad input => " + s);
    else
    {
        if (!findValueOfBitcoin(s, value))
            std::cout << "Can't find a date lower than " << s << std::endl;
        else if (!std::isspace(s1.at(0)) || s1.find_first_not_of(BASE, 1) != std::string::npos || s1.size() <= 1)
            printErr("bad input => " + s1);
        else
        {
            ss << s1;
            ss >> base_val;
            s1.erase(0, 1);
            if (ss.fail() || base_val > 1000)
                printErr("too large a number");
            else if (base_val < 0)
                printErr("not a positive number.");
            else
            {
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
        throw std::runtime_error("File Error");
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
    double val;
    std::string s;
    std::string s1;
    std::getline(stream, s, ',');
    if (!BitcoinExchange::checkValidDateFormat(s, 10))
        throw std::runtime_error("Bad input: " + s);
    std::getline(stream, s1);
    stream.clear();
    stream.str("");
    stream << s1;
    stream >> val;
    if (s1.size() == 0 || s1.find_first_not_of(BASE_DATE_VAL) != std::string::npos || stream.fail())
        throw std::runtime_error("Bad input: " + s1);
    BitcoinExchange::_tree[s] = val;
}

void BitcoinExchange::setTree(void)
{
    std::ifstream data("data.csv");
    if (!data)
        throw std::runtime_error("File Error");
    std::string s;
    std::getline(data, s);
    while (std::getline(data, s))
        fillTree(s);
}
/*---------------------------STATIC MEMBER/FUNCTION---------------------------*/
std::map<std::string,double> BitcoinExchange::_tree;