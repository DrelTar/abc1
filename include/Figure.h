#include "Enums.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Triangle.h"
#ifndef FIGURE_H
#define FIGURE_H

typedef struct
{
    Color color;
    Type type;
    Circle circle;
    Rectangle rectangle;
    Triangle triangle;
} Figure;

double Area(Figure figure);

void Display(Figure figure, FILE* file);

#endif // FIGURE_H
