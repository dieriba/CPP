#include "./includes/Harl.hpp"

Harl::Harl()
{
    Harl::_func_name[0] = "debug";
    Harl::_func_name[1] = "info";
    Harl::_func_name[2] = "warning";
    Harl::_func_name[3] = "error";
    Harl::_harl[0] = &Harl::debug;
    Harl::_harl[1] = &Harl::info;
    Harl::_harl[2] = &Harl::warning;
    Harl::_harl[3] = &Harl::error;
}

/*--------------------------PUBLIC_--------------------------*/

int Harl::find_index(const std::string& level)
{
    int i = -1;

    while (++i < 4)
    {
        if (_func_name[i].compare(level) == 0)
            return (i);
    }
    return (-1);
}

void Harl::complain(std::string level)
{
    int i = this -> find_index(level);
    if (i < 0)
        return ;
    (this ->*(_harl[i]))();
}
/*--------------------------PUBLIC_--------------------------*/

/*--------------------------PRIVATE_--------------------------*/
void Harl::debug(void)
{
    std::cout << "DEBUG: TRYING TO DEBUG THIS SHITTY PROG RIGTH NOW"
              << std::endl;
}

void Harl::info(void)
{
    std::cout << "INFO: THIS PROGRAM IS REALLY BAD IMPLEMENTED"
              << std::endl;
}

void Harl::warning(void)
{
    std::cout << "WARNING: THIS PROGRAM IS REALLY CRAP, BEWARY"
              << std::endl;
}

void Harl::error(void)
{
    std::cerr << "ERROR: YOU DID NOT LISTEN TO THE PREVIOUS STATEMENT DID YOU"
              << std::endl;
}
/*--------------------------PRIVATE_--------------------------*/