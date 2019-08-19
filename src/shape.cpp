#include "../include/shape.h"
#include "../include/rectangle.h"
#include "../include/circle.h"
#include "../include/square.h"
#include "../include/composite.h"
#include "../include/shapeFormatter.h"

#include "../include/triangle.h"
#include "../include/point.h"

#include <iostream>

using std::cout;
using std::endl;

Shape* Shape::createTriangle(vector<Point*> points) {
    return new Triangle(points);
}


Shape* Shape::createRectangle(double height, double width) {
    return new Rectangle(height, width);
}

Shape* Shape::createCircle(double radius) {
    return new Circle(radius);
}

Shape* Shape::createSqaure(double side) {
    return new Square(side);
}

Shape* Shape::createComposite() {
    return new Composite();
}


// Shape* Shape::createComposite(ShapeFormatter * shapeFormatter) {
//     return new Composite(shapeFormatter);
// }

Shape::Shape(string type) {
    this->_type = type;
}

// Shape::Shape(ShapeFormatter * shapeFormatter) {
//     this->_shapeFormatter = shapeFormatter;
// }

// string Shape::getFormattedData() {
//     this->_shapeFormatter->formatting(this);
//     return this->_shapeFormatter->getFormattedData();
// }


string Shape::getFormattedData(ShapeFormatter *shapeFormatter) {
    shapeFormatter->formatting(this);
    return shapeFormatter->getFormattedData();
}

void Shape::add(Shape* shape) {
    // throw exception
}
