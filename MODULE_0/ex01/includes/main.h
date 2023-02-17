# ifndef _MAIN_H
# define _MAIN_H
	# include <string>
	# include <string.h>
	# include <iostream>
	# include <iomanip>
bool	 getOneLine(std::string& line);
void	print_and_get_line(std::string line, std::string& info);
bool 	is_blank(const std::string& line);
int    check_input_index(std::string &index);
# endif