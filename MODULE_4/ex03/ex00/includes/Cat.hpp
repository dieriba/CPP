#ifndef _CAT_HPP_
#define _CAT_HPP_
#include "Animal.hpp"

class Cat : public Animal
{
    public:
        Cat();
        Cat(const Cat& rhs);
        Cat& operator=(const Cat& rhs);
        ~Cat();
        
        void makeSound() const;
        const std::string& getType() const;
    protected:
        std::string type;
};

#endif