#ifndef UTSHAPE_H
#define UTSHAPE_H
#include "./include/shape.h"
#include "./include/point.h"

#include <string>
using std::string;

TEST(Shape, createTriangle) {
    Point* p1 = new Point(0,0);
    Point* p2 = new Point(2, 0);
    Point* p3 = new Point(0, 2);
    vector<Point*> points;
    points.push_back(p1);
    points.push_back(p2);
    points.push_back(p3);
    // Heron's formula
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

#endif