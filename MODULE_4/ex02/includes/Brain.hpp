#ifndef _BRAIN_HPP
#define _BRAIN_HPP
#include <iostream>
#include <string>

class Brain
{
    public:
        Brain();
        ~Brain();
        Brain(const Brain& rhs);
        Brain& operator=(const Brain& rhs); 
    private:
        std::string ideas[100];
};

#endif