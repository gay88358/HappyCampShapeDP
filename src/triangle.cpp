#include "../include/triangle.h"

#include <iostream>

using std::cout;
using std::endl;

Triangle::Triangle(double sideA, double sideB, double sideC): Shape("Triangle") {
    this->_sideA = sideA;
    this->_sideB = sideB;
    this->_sideC = sideC;
}

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

double Triangle::getSideA() {
    return this->_sideA;
}

double Triangle::getSideB() {
    return this->_sideB;
}

double Triangle::getSideC() {
    return this->_sideC;
}