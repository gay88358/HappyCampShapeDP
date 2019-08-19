#ifndef CIRCLE_H
#define CIRCLE_H

#include "./shape.h"

class Circle : public Shape {
public:
    Circle(double radius);
    virtual double calculateArea();
private:
    double _radius;
};


#endif