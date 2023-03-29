#include "./includes/main.h"

void change_line_or_not(std::string& line, const std::string& s1, const std::string& s2)
{
    std::size_t found = 0;
    std::size_t len = s1.length();
    while ((found = line.find(s1, found)) != std::string::npos)
    {
        line.erase(found, len);
        line.insert(found, s2);
        found += len;
    }
}

void read_write_to_file(std::ifstream& file, const std::string& out_f, const std::string& s1, const std::string& s2)
{
    std::string line;
    std::ofstream outfile(out_f.c_str());

    check_files(outfile, out_f);
    while (getline(file, line))
    {
        change_line_or_not(line, s1, s2);
        outfile << line << std::endl;
    }
}