#ifndef _ANIMAL_HPP_
#define _ANIMAL_HPP_
#include <iostream>
#include <string>

class Animal
{
    public:
        Animal();
        virtual void makeSound() const;
        virtual ~Animal();
        virtual const std::string& getType() const;
    protected:
        std::string type;
};

#endif