#ifndef _DOG_HPP_
#define _DOG_HPP_
#include "Animal.hpp"

class Dog : public Animal
{
    public:
        Dog();
        Dog(const Dog& rhs);
        Dog& operator=(const Dog& rhs);
        ~Dog();

        void makeSound() const;
        const std::string& getType() const;
    protected:
        std::string type;
};

#endif