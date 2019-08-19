#include "../include/rectangle.h"


Rectangle::Rectangle(double height, double width): Shape("Rectangle") {
    this->_height = height;
    this->_width = width;
}


double Rectangle::calculateArea() {
    return this->_height * this->_width;
}
