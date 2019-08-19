#include "../include/shapeFormatter.h"
#include "../include/xmlShapeFormatter.h"
#include "../include/plainTextShapeFormatter.h"

ShapeFormatter* ShapeFormatter::xmlFormatter() {
    return new XMLShapeFormatter();
}
ShapeFormatter* ShapeFormatter::plainTextFormatter() {
    return new PlainTextShapeFormatter();
}

ShapeFormatter::ShapeFormatter() {

}

Shape* ShapeFormatter::getShape() {
    return this->_shape;
}

string ShapeFormatter::getFormattedData() {
    return this->_formattedData;
}

