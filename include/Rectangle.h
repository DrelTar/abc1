#include "Point.h"
#include "Figure.h"
#include "stdio.h"
#ifndef RECTANGLE_H
#define RECTANGLE_H

class Rectangle : public Figure {
public:
    Point leftTop;
    Point rightBottom;
    double Area() override;
    void Display(FILE* file) override;
    void Generate() override;
    void Read(FILE* file) override;
    Rectangle();
    ~Rectangle();
};

#endif // RECTANGLE_H
