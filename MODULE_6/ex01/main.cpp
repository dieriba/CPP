#include "./includes/Serialize.hpp"

void checkAdresses(Data* ptr)
{
    uintptr_t val = Serialize::serialize(ptr);
    std::cout << "Base value pointer is: " << ptr << std::endl;
    std::cout << "Serialize pointer value is: " << val << std::endl;
    std::cout << "Deserialize pointer value is: " << Serialize::deserialize(val) << std::endl;
}


int main ()
{
    try
    {
        Data obj;
        checkAdresses(&obj);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }   
}