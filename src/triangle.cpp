#include "../include/triangle.h"

#include <iostream>

using std::cout;
using std::endl;

Triangle::Triangle(vector<Point*> points) : Shape("Triangle") {
    this->_points = points;
    validate();
}


void Triangle::validate() {
    // validate
    cout << "empty validate" << endl;
}

double Triangle::calculateArea() {
    // calculate triangle given three points
    cout << "dummy calculate area" << endl;
    return 123;   
}
