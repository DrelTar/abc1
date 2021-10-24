#include "Point.h"
#include "Figure.h"
#include "stdio.h"
#ifndef TRIANGLE_H
#define TRIANGLE_H

class Triangle : public Figure {
public:
    Point first;
    Point second;
    Point third;
    double Area() override;
    void Display(FILE* file) override;
    void Generate() override;
    void Read(FILE* file) override;
};

#endif // TRIANGLE_H
