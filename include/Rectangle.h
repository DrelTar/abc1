#include "Point.h"
#include "stdio.h"
#ifndef RECTANGLE_H
#define RECTANGLE_H

typedef struct
{
    Point leftTop;
    Point rightBottom;
} Rectangle;

double Area(Rectangle rectangle);

void Display(Rectangle rectangle, FILE* file);

Rectangle GenerateRectangle();

Rectangle ReadRectangle(FILE* file);

#endif // RECTANGLE_H
