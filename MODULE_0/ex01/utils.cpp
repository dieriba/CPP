#include "./includes/main.h"

void	print_and_get_line(std::string line, std::string& info)
{
	if (std::cin)
	{
		std::cout << line;
		getline(std::cin, info);
	}
}

int print_err(void)
{
    std::cerr << "Index value must only be between 0 and 7" << std::endl;
    return (-1);
}

int    check_input_index(std::string &index)
{
    size_t  i;

    i = -1;
    while (index[++i])
        if (!isdigit(index[i]))
            return (print_err());
    if (i > 1)
        return (print_err());
    return (index[0] - 48);
}

