#ifndef UTPOINT_H
#define UTPOINT_H
#include "./include/point.h"

TEST(Point, createPoint) {
    Point *p = new Point(1, 2);
    ASSERT_TRUE(p != nullptr);
}

TEST(Point, distance) {
    Point *p1 = new Point(2, 2);
    Point *p2 = new Point(1, 2);
    double distance = p1->getDistanceFrom(p2);
    ASSERT_EQ(1, distance);
}

#endif