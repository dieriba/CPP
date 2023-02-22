#include "./includes/Cat.hpp"
#include "./includes/Dog.hpp"
#include "./includes/WrongCat.hpp"
#include "./includes/WrongAnimal.hpp"

int main()
{
    const Animal* meta = new (std::nothrow) Animal();
    if (!meta) return (1);
    const Animal* j = new (std::nothrow) Dog();
    if (!j) return (1);
    const WrongAnimal* i = new (std::nothrow) WrongCat();
    if (!i) return (1);
    std::cout << j -> getType() << " " << std::endl;
    std::cout << i -> getType() << " " << std::endl;
    i -> makeSound(); //will output the cat sound!
    j -> makeSound();
    meta -> makeSound();
    delete i;
    delete j;
    delete meta;
    return 0;
}