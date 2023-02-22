#include "./includes/Cat.hpp"
#include "./includes/Dog.hpp"
#include "./includes/WrongCat.hpp"
#include "./includes/WrongAnimal.hpp"

int main()
{
    int i = -1;
    const Animal* a = new (std::nothrow) Dog();
    if (a == NULL) return (1);
    const Animal* b = new (std::nothrow) Dog();
    if (b == NULL) return (1);
    const Animal* j = new (std::nothrow) Cat();
    if (j == NULL) return (1);
    const Animal* k = new (std::nothrow) Cat();
    if (k == NULL) return (1);
    const Animal * animals[5] = {a, b, j, k, NULL};
    while (animals[++i])
        delete animals[i];
    return 0;
}