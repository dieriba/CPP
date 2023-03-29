#include <string>
#include <iostream>

int main(void)
{
    std::string brainz = "HI THIS IS BRAIN";
    std::string& stringRef = brainz;
    std::string* stringPtr = &brainz;

    std::cout << "Adress of brainz is: " << &brainz << std:: endl;
    std::cout << "Adress of stringPtr is: " << stringPtr << std:: endl;
    std::cout << "Adress of stringRef is: " << &stringRef << std:: endl;
    std::cout << std::endl;
    std::cout << "Value of brainz is: " << brainz << std:: endl;
    std::cout << "Value of stringPtr is: " << (*stringPtr) << std:: endl;
    std::cout << "Value of stringRef is: " << stringRef << std:: endl;
}