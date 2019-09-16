#ifndef UTILITY_H
#define UTILITY_H

#include <string>

using std::string;

class Utility {
public:
    static string convertStringWithPrecision(double price, int precision);
};

#endif