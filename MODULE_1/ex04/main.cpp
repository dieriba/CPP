#include "./includes/main.h"



int main(int argc, char **argv)
{
    if (argc != 4)
        return (1);
    std::ifstream file(argv[1]);
    std::string file_name(argv[1]);
    std::string s1(argv[2]);
    std::string s2(argv[3]);

    check_files(file, file_name);
    read_write_to_file(file, file_name.append(".replace"), s1, s2);
}