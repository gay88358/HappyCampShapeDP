#ifndef XMLSHAPEFORMATTER_H
#define XMLSHAPEFORMATTER_H

#include "./shapeFormatter.h"



class XMLShapeFormatter : public ShapeFormatter {
public:
    XMLShapeFormatter();
    virtual void formatting(Shape* shape);
};

#endif