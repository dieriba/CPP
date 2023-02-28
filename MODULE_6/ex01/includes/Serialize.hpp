#ifndef __SERIALIZE_HPP_
#define __SERIALIZE_HPP_
#include <stdint.h>
#include <iostream>
typedef struct Data
{
    int type;
    char *name;
} Data;


class Serialize
{
    public:
        Serialize(/* args */);
        ~Serialize();
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
};
#endif