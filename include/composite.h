#ifndef COMPOSITE_H
#define COMPOSITE_H

#include "./shape.h"

class Composite : public Shape {
public:
    Composite();
    virtual void add(Shape*);
    virtual double calculateArea();
};

#endif