#include "Point.h"
#include "stdio.h"
#ifndef TRIANGLE_H
#define TRIANGLE_H

typedef struct
{
    Point first;
    Point second;
    Point third;
} Triangle;

double Area(Triangle triangle);

void Display(Triangle triangle, FILE* file);

Triangle GenerateTriangle();

Triangle ReadTriangle(FILE* file);

#endif // TRIANGLE_H
