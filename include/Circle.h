#include "Point.h"
#include "stdio.h"
#ifndef CIRCLE_H
#define CIRCLE_H


typedef struct
{
    Point center;
    int radius;
} Circle;

double Area(Circle circle);

void Display(Circle circle, FILE* file);

Circle GenerateCircle();

Circle ReadCircle(FILE* file);

#endif // CIRCLE_H
