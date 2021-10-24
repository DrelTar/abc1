#include "Point.h"
#include "Figure.h"
#include "stdio.h"
#ifndef CIRCLE_H
#define CIRCLE_H

class Circle : public Figure {
public:
    Point center;
    int radius;
    double Area() override;
    void Display(FILE* file) override;
    void Generate() override;
    void Read(FILE* file) override;
    Circle();
    ~Circle();
};

#endif // CIRCLE_H
