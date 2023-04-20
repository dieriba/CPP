# include <string>
# include <sstream>
# include <map>
# include <fstream>
# include <cstdlib>
# include <iostream>
# include <algorithm>
# include <set>

# define BASE "0123456789-."
# define BASE_DATE "0123456789-"
# define BASE_DATE_VAL "0123456789."

class BitcoinExchange
{
    public:
        BitcoinExchange();
        BitcoinExchange(const std::string& filename);
        BitcoinExchange(const BitcoinExchange& rhs);
        BitcoinExchange& operator=(const BitcoinExchange& rhs);
        ~BitcoinExchange();

        /*GETTERS*/
        const std::string& getFilename(void) const;

        /*STATIC MEMBER*/
        static void fillTree(const std::string& line);
        static std::map<std::string,double> _tree;
        static void setTree(void);
        static void printErr(const std::string& err);
        static bool checkValidDateFormat(std::string& date, const size_t& len);

        /*MEMBER FUNC*/
        void printRate(void) const;
        void clearAndPrint(std::string& line) const;
        bool findValueOfBitcoin(const std::string& date, double& value) const;
    private:
        std::string _filename;
};
