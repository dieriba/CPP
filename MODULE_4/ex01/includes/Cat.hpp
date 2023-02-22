#ifndef _CAT_HPP_
#define _CAT_HPP_
#include "Animal.hpp"
#include "Brain.hpp"
class Cat : public Animal
{
    public:
        Cat();
        ~Cat();
        Cat(const Cat& rhs);
        Cat& operator=(const Cat& rhs);
        void makeSound() const;
        const std::string& getType() const;
    private:
        Brain *idea;
};

#endif