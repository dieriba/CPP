#ifndef _ANIMAL_HPP_
#define _ANIMAL_HPP_
#include <iostream>
#include <string>

class Animal
{
    public:
        Animal();
        Animal(const Animal& rhs);
        Animal& operator=(const Animal& rhs);
        virtual ~Animal();
        virtual void makeSound() const = 0;
        virtual const std::string& getType() const = 0;
    protected:
        std::string type;
};

#endif