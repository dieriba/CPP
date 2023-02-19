#include "./includes/Harl.hpp"

Harl::Harl()
{
    Harl::_func_name[0] = "DEBUG";
    Harl::_func_name[1] = "INFO";
    Harl::_func_name[2] = "WARNING";
    Harl::_func_name[3] = "ERROR";
}

/*--------------------------PUBLIC_--------------------------*/

int Harl::find_index(std::string level)
{
    int i = -1;

    while (++i < 4)
    {
        if (this -> _func_name[i].compare(level) == 0)
            return (i);
    }
    return (-1);
}

int Harl::complain(std::string level)
{
    int i = this -> find_index(level);
    if (i < 0)
        return (-1);
    switch (i)
    {
        case 0:
            this -> debug();
            this -> info();
            this -> warning();
            this -> error();
            break ;
        case 1:
            this -> info();
            this -> warning();
            this -> error();
            break ;
        case 2:
            this -> warning();
            this -> error();
            break;
        case 3:
            this -> error();
        default:
            break;
    }
    return (0);
}
/*--------------------------PUBLIC_--------------------------*/

/*--------------------------PRIVATE_--------------------------*/
void Harl::debug(void)
{
    std::cout << "[" "DEBUG" "]" << std::endl
              << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger" << std::endl
              << "I really do!" << std::endl
              << std::endl;
}

void Harl::info(void)
{
    std::cout << "[" "INFO" "]" << std::endl
              << "I cannot believe adding extra bacon costs more mone" << std::endl
              << "You didn't put enough bacon in my burger! if you did, I wouldn't be asking for more!" << std::endl
              << std::endl;
}

void Harl::warning(void)
{
    std::cout << "[" "WARNING" "]" << std::endl
              << "I think I deserve to have some extra bacon for free" << std::endl
              << "I've been coming for years whereas you started working here since last month"  << std::endl
              << std::endl;
}
void Harl::error(void)
{
    std::cerr << "[" "ERROR" "]" << std::endl
              << "ERROR: YOU DID NOT LISTEN TO THE PREVIOUS STATEMENT DID YOU" << std::endl
              << std::endl;
}
/*--------------------------PRIVATE_--------------------------*/