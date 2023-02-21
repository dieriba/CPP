#ifndef _WRONG_ANIMAL_HPP_
#define _WRONG_ANIMAL_HPP_
#include <iostream>
#include <string>

class WrongAnimal
{
    public:
        WrongAnimal();
        virtual void makeSound() const;
        virtual ~WrongAnimal();
        virtual const std::string& getType() const;
    protected:
        std::string type;
};

#endif