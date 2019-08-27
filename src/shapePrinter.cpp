#include "../include/shapePrinter.h"


ShapePrinter::ShapePrinter() {
    this->_information = "";
}

void ShapePrinter::generateDisplayInformation(Shape *shape) {
    int area = shape->calculateArea();
    this->_information += "this area is " + std::to_string(area);
}

void ShapePrinter::generateDisplayInformation(vector<Shape*> shapes) {
    int area = 0;
    for (int i = 0; i < shapes.size(); i++) {
        area += shapes[i]->calculateArea();
    }
    this->_information += "this area is " + std::to_string(area);
}

string ShapePrinter::getDisplayInformation() {
    return this->_information;
}