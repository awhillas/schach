#pragma once

#include <vector>
#include <string>
#include <sstream>
#include <iterator>


template<typename T>
void split(const std::string &s, char delim, T result);

std::vector<std::string> split(const std::string &s, char delim);
