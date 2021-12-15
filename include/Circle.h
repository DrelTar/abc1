#include "Point.h"
#include "stdio.h"
#ifndef CIRCLE_H
#define CIRCLE_H


typedef struct Circle
{
    static unsigned int* seed;
    FILE* output_file;
    FILE* input_file;
    Point center;
    int radius;
} Circle;

double Area(Circle circle);

void* DisplayCircle(void* circle);

void* GenerateCircle(void* circle);

void* ReadCircle(void* circle);

#endif // CIRCLE_H
