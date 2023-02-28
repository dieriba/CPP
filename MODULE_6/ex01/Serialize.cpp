#include "./includes/Serialize.hpp"

uintptr_t Serialize::serialize(Data* ptr)
{
    void* p = ptr;
    uintptr_t val = reinterpret_cast<uintptr_t>(p);
    return val;
};
Data* Serialize::deserialize(uintptr_t raw)
{
    Data* p = reinterpret_cast<Data*>(raw);
    return p;
};