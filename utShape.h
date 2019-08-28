#ifndef UTSHAPE_H
#define UTSHAPE_H
#include <iostream>
#include "./include/shape.h"
#include "./include/point.h"
#include "./include/shapePrinter.h"
#include "./include/rectangle.h"
#include "./include/circle.h"
#include "./include/square.h"
#include "./include/triangle.h"
#include "./include/composite.h"

#include <string>
using std::string;
using std::cout;
using std::endl;

TEST(Shape, unitTestStepTemplate) {
// 1. Create the object that you want to test.

// 2. Invoke the method of object that you want to test.

// 3. Verify the state of object
}


TEST(Shape, createTriangleContainedThreeSide) {
    // create
    Triangle *triangle = new Triangle(1, 2, 3);
    //Shape *shape = Shape::createTriangle(points);
    ASSERT_EQ(1, triangle->getSideA());
    ASSERT_EQ(2, triangle->getSideB());
    ASSERT_EQ(3, triangle->getSideC());
}

TEST(Shape, createTriangle) {
    Point* p1 = new Point(0,0);
    Point* p2 = new Point(2, 0);
    Point* p3 = new Point(0, 2);
    vector<Point*> points;
    points.push_back(p1);
    points.push_back(p2);
    points.push_back(p3);
    // Heron's formula
    // Shape *shape = new Triangle(points);
    Shape *shape = Shape::createTriangle(points);
    ASSERT_EQ(2, shape->calculateArea());
}


TEST(Shape, createRectangle) {
    Shape *shape = Shape::createRectangle(1, 2);
    ASSERT_EQ(1 * 2, shape->calculateArea());
}

TEST(Shape, createCircle) {
    Shape *shape = Shape::createCircle(6);
    ASSERT_EQ(6 * 3.14, shape->calculateArea());
}

TEST(Shape, createSquare) {
    Shape *shape = Shape::createSqaure(1.5);
    ASSERT_EQ(1.5 * 1.5, shape->calculateArea());
}


TEST(ShapePrinter, getShapeInformation) {
// creat an object
    ShapePrinter *printer = new ShapePrinter();
// invoke operation on an object
    printer->generateDisplayInformation(Shape::createSqaure(1));
// assert to chech the result
    string information = printer->getDisplayInformation();
    ASSERT_EQ("this area is 1", information);
}

TEST(ShapePrinter, getShapesInformation) {
// creat an object
// container: vector, list, array
    vector<Shape*> shapes;
    shapes.push_back(Shape::createCircle(1));
    shapes.push_back(Shape::createSqaure(2));
    shapes.push_back(Shape::createRectangle(2, 3));

    ShapePrinter *printer = new ShapePrinter();
// invoke operation on an object
    printer->generateDisplayInformation(shapes);
// assert to chech the result
    string information = printer->getDisplayInformation();
    ASSERT_EQ("this area is 13", information);
}


TEST(Shape, createCompositeShape) {
// create a composite object
    Shape *composite = Shape::createComposite();
    composite->add(Shape::createSqaure(2));
    composite->add(Shape::createRectangle(2, 3));
// invoke method of composite object
    double compositeArea = composite->calculateArea();
// verify the state of an object
    double sqaureArea = 2 * 2;
    double rectangleArea = 2 * 3;
    ASSERT_EQ(sqaureArea + rectangleArea, compositeArea);
}



#endif