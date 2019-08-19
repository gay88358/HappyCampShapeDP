#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <vector>
#include "./point.h"
using std::vector;
#include "./shape.h"

class Triangle : public Shape{
public:
    Triangle(vector<Point*> points);
    virtual double calculateArea();
private:
    void validate();
    vector<Point*> _points;
};

#endif