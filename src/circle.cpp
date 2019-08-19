#include "../include/circle.h"

Circle::Circle(double radius) : Shape("circle") {
    this->_radius = radius;
}


double Circle::calculateArea() {
    return 3.14 * this->_radius;
}
