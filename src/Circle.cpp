#include "Circle.h"
#include "math.h"
#include "stdio.h"
#define _USE_MATH_DEFINES

Circle::Circle()
{
    center = {0, 0};
    radius = 1;
}

Circle::Circle(int a, int b, int c)
{
    center.x = a;
    center.y = b;
    radius = c;
}

double Circle::Square()
{
    return M_PI * double(radius) * double(radius);
}

void Circle::Display(FILE* file)
{
    fprintf(file, "%s%u%s%u%s%u%s", "Circle: \n X: ", center.x, "\n Y: ", center.y, "\n Radius: ", radius, "\n");
}

Circle::~Circle()
{
    delete &center;
    delete &radius;
}
