#ifndef MAIN_H
#define MAIN_H
#include <iostream>
#include <fstream>
#include <string>
#include <cerrno>
#include <stdlib.h>

void check_files(std::ifstream& file, std::string &file_name);
void check_files(std::ofstream& file, std::string &file_name);
void read_write_to_file(std::ifstream& file, std::string& out_f, std::string& s1, std::string& s2);
#endif