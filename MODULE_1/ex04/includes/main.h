#ifndef MAIN_H
#define MAIN_H
#include <iostream>
#include <fstream>
#include <string>
#include <cerrno>
#include <stdlib.h>

void check_files(const std::ifstream& file, const std::string &file_name);
void check_files(const std::ofstream& file, const std::string &file_name);
void read_write_to_file(std::ifstream& file, const std::string& out_f, const std::string& s1, const std::string& s2);
#endif