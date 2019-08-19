#include "../include/composite.h"

Composite::Composite(): Shape("Composite") {

}

Composite::Composite(ShapeFormatter *shapeFormatter): Shape(shapeFormatter) {
}

double Composite::calculateArea() {
    double totalArea = 0.;
    for (int i = 0; i < this->_shapes.size(); i++) {
        totalArea += this->_shapes[i]->calculateArea();
    }
    return totalArea;
}


void Composite::add(Shape* shape) {
    this->_shapes.push_back(shape);
}