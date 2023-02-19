#ifndef _HARL_HPP_
#define _HARL_HPP_
#include <iostream>
#include <string>

class Harl
{
    public:
        Harl();
		int complain(std::string level);
        int find_index(std::string level);
    private:
        void debug(void);
        void info(void);
        void warning(void);
        void error(void);
        std::string _func_name[4];
};

#endif