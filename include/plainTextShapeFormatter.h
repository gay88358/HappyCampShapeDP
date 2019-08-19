#ifndef PLAINTEXTSHAPEFORMATTER_H
#define PLAINTEXTSHAPEFORMATTER_H

#include "./shapeFormatter.h"

class PlainTextShapeFormatter : public ShapeFormatter {
public:
    PlainTextShapeFormatter();
    virtual void formatting(Shape* shape);
};

#endif