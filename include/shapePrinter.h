
#ifndef SHAPEPRINTER_H
#define SHAPEPRINTER_H

#include "./shape.h"
#include <string>
#include <vector>

using std::string;
using std::vector;

class ShapePrinter {
public:
    ShapePrinter();
    void generateDisplayInformation(Shape *shape);
    void generateDisplayInformation(vector<Shape*> shapes);
    string getDisplayInformation();
private:
    string _information;
};

#endif