#ifndef SHAPE_H
#define SHAPE_H
#include <string>
#include <vector>

using std::vector;
using std::string;

class Point;

class Shape {
public:
// factory method
    static Shape* createTriangle(vector<Point*> points);
    static Shape* createRectangle(double height, double width);
    static Shape* createCircle(double radius);
    static Shape* createSqaure(double side);
    static Shape* createComposite();
    Shape(string type);
    // override method for composite
    // other shape type call this method
    // will throw exception
    virtual void add(Shape*);
    virtual double calculateArea() = 0;
protected:
    vector<Shape*> _shapes;
private:
    string _type;
};

#endif