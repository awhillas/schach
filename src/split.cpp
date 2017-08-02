#include <vector>
#include <string>
#include <sstream>
#include <iterator>


using namespace std;

#if !defined(CPP_SPLIT_CPP_)
#define CPP_SPLIT_CPP_

template<typename T>
void split(const string &s, char delim, T result) {
    stringstream ss;
    ss.str(s);
    string item;
    while (getline(ss, item, delim)) {
        *(result++) = item;
    }
}

vector<string> split(const string &s, char delim) {
    vector<string> elems;
    split(s, delim, back_inserter(elems));
    return elems;
}

#endif