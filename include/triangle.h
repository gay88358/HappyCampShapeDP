#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <vector>
#include "./point.h"
using std::vector;
#include "./shape.h"

class Triangle : public Shape{
public:
    Triangle(vector<Point*> points);
    Triangle(double sideA, double sideB, double sideC);
    virtual double calculateArea();
    double getSideA();
    double getSideB();
    double getSideC();
private:
    void validate();
    vector<Point*> _points;
// just for demo, don't use to two different intention constructor 
// in the production code
    double _sideA;
    double _sideB;
    double _sideC;
};

#endif