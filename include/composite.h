#ifndef COMPOSITE_H
#define COMPOSITE_H

#include "./shape.h"

class Composite : public Shape {
public:
    Composite();
    Composite(ShapeFormatter*);
    virtual double calculateArea();
    virtual void add(Shape* shape);
private:
};

#endif