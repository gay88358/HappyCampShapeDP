#ifndef SHAPEFORMATTER
#define SHAPEFORMATTER

#include "./shape.h"
#include <string>
using std::string;
using std::to_string;

class ShapeFormatter {
public:
    static ShapeFormatter* xmlFormatter();
    static ShapeFormatter* plainTextFormatter();
    ShapeFormatter();
    virtual void formatting(Shape* shape) = 0;
    Shape* getShape();
    string getFormattedData();
protected:
    Shape * _shape;
    string _formattedData;
};


#endif