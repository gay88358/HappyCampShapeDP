#ifndef POINT_H
#define POINT_H

class Point {
public:
    Point(int x, int y);
    double getDistanceFrom(Point*p);
private:
    int _x;
    int _y;
};

#endif