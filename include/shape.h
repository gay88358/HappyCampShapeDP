#ifndef SHAPE_H
#define SHAPE_H
#include <string>
#include <vector>

using std::vector;
using std::string;

class Point;
class ShapeFormatter;
class Shape {
public:
    static Shape* createTriangle(vector<Point*> points);
    static Shape* createRectangle(double height, double width);
    static Shape* createCircle(ShapeFormatter * shapeFormatter, double radius);
    static Shape* createCircle(double radius);
    static Shape* createSqaure(double side);
    static Shape* createComposite();
    static Shape* createComposite(ShapeFormatter * shapeFormatter);
    Shape(string type);
    Shape(ShapeFormatter *);
    // override method for composite
    // other shape type call this method
    // will throw exception
    virtual void add(Shape* shape);
    virtual double calculateArea() = 0;
    string getFormattedData();
protected:
    vector<Shape*> _shapes;
private:
    string _type;
    ShapeFormatter *_shapeFormatter;
};

#endif