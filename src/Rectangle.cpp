#include "Rectangle.h"
#include "stdlib.h"
#include "stdio.h"

Rectangle::Rectangle()
{
    leftTop = {0, 1};
    rightBottom = {1, 0};
}

Rectangle::Rectangle(int a, int b, int c, int d)
{
    leftTop.x = a;
    leftTop.y = b;
    rightBottom.x = c,
    rightBottom.y = d;
}

double Rectangle::Square()
{
    return abs(leftTop.x - rightBottom.x) * abs(leftTop.y - rightBottom.y);
}

void Rectangle::Display(FILE* file)
{
    fprintf(file, "%s%u%s%u%s%u%s%u%s", "Rectangle: \n Left Top X: ", leftTop.x, "\n Left Top Y: ", leftTop.y, "\n Right Bottom X: ", rightBottom.x,
           "\n Right Bottom Y: ", rightBottom.y, "\n");
}

Rectangle::~Rectangle()
{
    delete &leftTop;
    delete &rightBottom;
}
