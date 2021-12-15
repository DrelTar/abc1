#include "Enums.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Triangle.h"
#include "pthread.h"
#ifndef FIGURE_H
#define FIGURE_H

typedef struct
{
    pthread_t thread;
    Color color;
    Type type;
    Circle circle;
    Rectangle rectangle;
    Triangle triangle;
} Figure;

double Area(Figure figure);

void* DisplayFigure(void* figure);

#endif // FIGURE_H
