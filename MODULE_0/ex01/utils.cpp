#include "./includes/main.h"

void	print_and_get_line(const std::string& line, std::string& info)
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

int    check_input_index(const std::string &index)
{
	int		idx;

    idx = index[0] - 48;
    if (index.size() > 1 || (idx < 0 || idx > 7)) return (print_err());
	return (index[0] - 48);
}

const std::string formatString(const std::string& line)
{
	std::string res(line);

	if (line.size() > 10)
	{
		res.resize(10);
		res.at(9) = '.';
	}
	return res;
}
