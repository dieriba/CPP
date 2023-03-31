#include "./includes/Character.hpp"
#include "./includes/AMateria.hpp"
/*-----------------------------------CONSTRUCTOR/DESTRUCTOR-----------------------------------*/
Character::Character():name("dieriba"),i(0),collector(0)
{
    for (size_t i = 0; i < 5; i++)
        items[i] = 0;
};
Character::Character(const std::string& name):name(name),i(0),collector(0)
{
    for (size_t i = 0; i < 5; i++)
        items[i] = 0;
};
Character::Character(const Character& rhs):name(rhs.name),i(rhs.i),collector(0)
{
    for (size_t i = 0; i < 5; i++)
    {
        if (rhs.items[i])
            items[i] = rhs.items[i] -> clone();
        else
            items[i] = 0;
    }
    giveAmateriaItemLeftOver(rhs);
};
Character& Character::operator=(const Character& rhs)
{
    name = rhs.name;
    i = rhs.i;
    for (size_t i = 0; i < 5; i++)
    {
        if (items[i])
            delete items[i];
        if (rhs.items[i])
            items[i] = rhs.items[i] -> clone();
        else
            items[i] = 0;
    }
    giveAmateriaItemLeftOver(rhs);
    return (*this);
};
Character::~Character()
{
    int i = -1;
    _collector *tmp = collector;
    while (collector)
    {
        tmp = collector -> next;
        delete collector -> collector;
        delete collector;
        collector = tmp;
    }
    collector = NULL;
    while (items[++i])
        delete items[i];
};
/*-----------------------------------CONSTRUCTOR/DESTRUCTOR-----------------------------------*/

/*-----------------------------------MEMBER/FUNCTION-----------------------------------*/
const std::string& Character::getName(void) const {return name;};
void Character::equip(AMateria *m)
{
    if (m == NULL)
        return ;
    if (i == 4 && m)
    {
        delete m;
        return ;
    }
    items[i++] = m;
}
void Character::unequip(int idx)
{
    if ((idx < 0 || idx > 3) || items[idx] == NULL)
        return ;
    addLeftOver(idx);
}
void Character::use(int idx, ICharacter& target)
{
    if ((idx < 0 || idx > 3) || items[idx] == 0)
        return ;
    items[idx] -> use(target);
}

void Character::cleanLeftOver(void)
{
    _collector* next;

    while (collector)
    {
        next = collector -> next;
        delete collector -> collector;
        delete collector;
        collector = next;
    }
    collector = NULL;
}


void Character::giveAmateriaItemLeftOver(const Character& rhs)
{
    _collector* node;
    _collector* current;
    _collector* prev;

    current = NULL;
    cleanLeftOver();
    if (rhs.collector)
    {
        node = new (std::nothrow) _collector;
        if (node)
        {
            node -> collector = rhs.collector -> collector -> clone();
            node -> next = NULL;
        }
        collector = node;
        prev = node;
        current = rhs.collector -> next;
    }
    while (current)
    {
        node = new (std::nothrow) _collector;
        if (!node) break ;
        node -> collector = rhs.collector -> collector -> clone();
        if (!node -> collector) break ;
        node -> next = NULL;
        prev -> next = node;
        prev = node;
        current = rhs.collector -> next;
    }
}

void Character::addLeftOver(int idx)
{
    _collector *node;

    node = new (std::nothrow) _collector;
    node -> collector = NULL;
    node -> next = NULL;
    if (node)
    {
        node -> collector = items[idx];
        if (!collector)
            collector = node;
        else
        {
            node -> next = collector;
            collector = node;
        }
        items[idx] = 0;
        i = i - 1 < 0 ? 0 : i - 1;
    }
}

void Character::printEquippedMateria(void)
{
    int i = -1;

    if (items[0] == NULL)
        std::cout << "No Materia Equipped right now\n";
    while (items[++i])
    {
        std::cout << "Materia equipped: "
                  << items[i] -> getType()
                  << " Memory adress location: "
                  << items[i] << std::endl;
    }
}

void Character::printLeftOverMateria(void)
{
    _collector* node;

    node = collector;
    if (node == NULL)
        std::cout << "No LeftOver Materia\n";
    while (node)
    {
        std::cout << "Materia equipped: "
                  << node -> collector -> getType()
                  << " Memory adress location: "
                  << node -> collector << std::endl;
        node = collector -> next;
    }
}

/*-----------------------------------MEMBER/FUNCTION-----------------------------------*/
