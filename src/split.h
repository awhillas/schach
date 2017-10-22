#pragma once

#include <string>

using namespace std;

template<typename T>
void split(const string &s, char delim, T result);

vector<string> split(const string &s, char delim);
