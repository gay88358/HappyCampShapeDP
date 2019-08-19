#include "../include/plainTextShapeFormatter.h"




PlainTextShapeFormatter::PlainTextShapeFormatter() : ShapeFormatter() {

}


void PlainTextShapeFormatter::formatting(Shape *shape) {
    double area = shape->calculateArea();
    this->_formattedData = "the area is " + to_string(area);
}

