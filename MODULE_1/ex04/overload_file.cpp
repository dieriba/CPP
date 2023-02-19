#include "./includes/main.h"

void check_files(std::ifstream& file, std::string &file_name)
{
    if (file)
        return;
    std::cerr << "An error occured while trying to read the file: "
              << file_name << std::endl;
    exit(1);
}

void check_files(std::ofstream& file, std::string &file_name)
{
    if (file)
        return;
    std::cerr << "An error occured while trying to read the file: "
              << file_name << std::endl;
    exit(1);
}