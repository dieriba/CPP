#ifndef _MAIN_H
#define _MAIN_H
	#include <string>
	#include <string.h>
	#include <sstream>
	#include <iostream>
	#include <iomanip>
	bool	 getOneLine(std::string& line);
	void	print_and_get_line(const std::string& line, std::string& info);
	bool 	is_blank(const std::string& line);
	int    check_input_index(const std::string &index);
	const std::string formatString(const std::string& line);
#endif