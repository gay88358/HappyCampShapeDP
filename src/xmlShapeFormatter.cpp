#include "../include/xmlShapeFormatter.h"

XMLShapeFormatter::XMLShapeFormatter() : ShapeFormatter() {

}

void XMLShapeFormatter::formatting(Shape *shape) {
    double area = shape->calculateArea();
    string areaTag = "<area>" + to_string(area) + "</area>";
    this->_formattedData = areaTag;
}

