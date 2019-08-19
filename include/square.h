#ifndef SQUARE_H
#define SQUARE_H

#include "./shape.h"

class Square : public Shape {
public:
    Square(double side);
    virtual double calculateArea();
private:
    double _side;
};


#endif