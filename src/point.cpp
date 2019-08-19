#include "../include/point.h"

Point::Point(int x, int y) {
    this->_x = x;
    this->_y = y;
}

double Point::getDistanceFrom(Point* p) {
    // need to used math sqart and pow
    double xx = (this->_x - p->_x) * (this->_x - p->_x);
    double yy = (this->_y - p->_y) * (this->_y - p->_y);
    return yy;
}