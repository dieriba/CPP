#include "./includes/main.h"

void check_files(std::ifstream& file, const std::string &file_name)
{
    if (file && file.peek() != std::ifstream::traits_type::eof())
        return ;
    else if (file.peek() == std::ifstream::traits_type::eof())
        std::cerr << "Empty file" << std::endl;
    else
        std::cerr << "An error occured while trying to read the file: "
                << file_name << std::endl;
    exit(1);
}

void check_files(const std::ofstream& file, const std::string &file_name)
{
    if (file)
        return;
    std::cerr << "An error occured while trying to read the file: "
              << file_name << std::endl;
    exit(1);
}