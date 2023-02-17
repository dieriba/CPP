# include "./includes/main.h"

bool is_blank(const std::string& line)
{
    size_t  i = -1;
    bool    blank = true;

    while (line[++i])
        if (!isspace(line[i]))
            blank = false;
    return (blank);
}

bool getOneLine(std::string& line)
{
    if (getline(std::cin, line))
        return true;
    return false;
}