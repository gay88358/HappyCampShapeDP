#include "../include/square.h"

Square::Square(double side): Shape("Square") {
    this->_side = side;
}

double Square::calculateArea() {
    return this->_side * this->_side;
}