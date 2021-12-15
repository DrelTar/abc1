#include "Point.h"
#include "stdio.h"
#ifndef RECTANGLE_H
#define RECTANGLE_H

typedef struct Rectangle
{
    static unsigned int* seed;
    FILE* output_file;
    FILE* input_file;
    Point leftTop;
    Point rightBottom;
} Rectangle;

double Area(Rectangle rectangle);

void* DisplayRectangle(void* rectangle);

void* GenerateRectangle(void* rectangle);

void* ReadRectangle(void* rectangle);

#endif // RECTANGLE_H
