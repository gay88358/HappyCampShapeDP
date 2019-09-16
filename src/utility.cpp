#include "../include/utility.h"


#include <sstream>
#include <iomanip>

string Utility::convertStringWithPrecision(double price, int precision) {
    // Create an output string stream
    std::ostringstream streamObj3;
    // Set Fixed -Point Notation
    streamObj3 << std::fixed;
    // Set precision to 2 digits
    streamObj3 << std::setprecision(precision);
    //Add double to stream
    streamObj3 << price;
    // Get string from output string stream
    std::string strObj3 = streamObj3.str();
    return strObj3;
}

