#ifndef _WRONG_ANIMAL_HPP_
#define _WRONG_ANIMAL_HPP_
#include <iostream>
#include <string>

class WrongAnimal
{
    public:
        WrongAnimal();
        WrongAnimal(const WrongAnimal& rhs);
        WrongAnimal& operator=(const WrongAnimal& rhs);
        virtual ~WrongAnimal();
        
        virtual void makeSound() const;
        virtual const std::string& getType() const;
    protected:
        std::string type;
};

#endif