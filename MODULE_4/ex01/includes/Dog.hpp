#ifndef _DOG_HPP_
#define _DOG_HPP_
#include "Animal.hpp"
#include "Brain.hpp"
class Dog : public Animal
{
    public:
        Dog();
        ~Dog();
        Dog(const Dog& rhs);
        Dog& operator=(const Dog& rhs);
        void makeSound() const;
        const std::string& getType() const;
    private:
        Brain *idea;
};

#endif