#include "Point.h"
#include "stdio.h"
#ifndef TRIANGLE_H
#define TRIANGLE_H

typedef struct Triangle
{
    static unsigned int* seed;
    FILE* output_file;
    FILE* input_file;
    Point first;
    Point second;
    Point third;
} Triangle;

double Area(Triangle triangle);

void* DisplayTriangle(void* triangle);

void* GenerateTriangle(void* triangle);

void* ReadTriangle(void* triangle);

#endif // TRIANGLE_H
