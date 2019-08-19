#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "./shape.h"

class Rectangle : public Shape {
public:
    Rectangle(double height, double width);
    virtual double calculateArea();
private:
    double _height;
    double _width;
};

#endif