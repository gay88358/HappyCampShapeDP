#ifndef UTSHAPEFORMATTER_H
#define UTSHAPEFORMATTER_H

#include "./include/shapeFormatter.h"
#include "./include/shape.h"

TEST(ShapeFormatter, xmlformatting) {
    Shape *shape = Shape::createCircle(2);
    ShapeFormatter *formatter = ShapeFormatter::xmlFormatter();
    formatter->formatting(shape);
    string xmlFormat = formatter->getFormattedData();
    ASSERT_EQ("<area>6.280000</area>", xmlFormat);
}

TEST(ShapeFormatter, plainTextformatting) {
    Shape *shape = Shape::createCircle(2);
    ShapeFormatter *formatter = ShapeFormatter::plainTextFormatter();
    formatter->formatting(shape);
    string plainFormat = formatter->getFormattedData();
    ASSERT_EQ("the area is 6.280000", plainFormat);
}

#endif