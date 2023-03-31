#ifndef _WRONG_CAT_HPP_
#define _WRONG_CAT_HPP_
#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
    public:
        WrongCat();
        WrongCat(const WrongCat& rhs);
        WrongCat& operator=(const WrongCat& rhs);
        ~WrongCat();

        void makeSound() const;
        const std::string& getType() const;
    protected:
        std::string type;
};

#endif