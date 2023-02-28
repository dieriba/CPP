#ifndef __CONVERT_HPP_
#define __CONVERT_HPP_
#include <string>
#include <iostream>
#include <iomanip>
#define NUM "0123456789"
#define __INT_MIN_ -2147483648
class Converter
{
    public:
        Converter();
        Converter(const std::string literal);
        Converter(const Converter& rhs);
        Converter& operator=(const Converter& rhs);
        ~Converter();
        enum dataTypes 
        {
            CHAR,
            INT,
            FLOAT,
            DOUBLE,
            IMPOSSIBLE
        };

        static void convert(const std::string& literal);
        static bool checkInt(const std::string& literal);
        static bool checkChar(const std::string& literal);
        static bool checkDouble(const std::string& literal);
        static bool checkFloat(const std::string& literal);
        static void setTypes(const std::string& literal);
        static void printScalarConversion(const std::string& literal);
        static void printChar(const std::string& literal);
        static void printInt(const std::string& literal);
        static void printFloat(const std::string& literal);
        static void printDouble(const std::string& literal);
        static bool funValue(const std::string& literal, std::string& lit_cpy, dataTypes _type);
    private:
        const std::string literal;
        static enum dataTypes type;
};
#endif