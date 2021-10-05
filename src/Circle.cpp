#include "Circle.h"
#include "math.h"
#include "time.h"
#include "stdlib.h"r
#define _USE_MATH_DEFINES

double Area(Circle circle)
{
    return M_PI * double(circle.radius) * double(circle.radius);
}

void Display(Circle circle, FILE* file)
{
    fprintf(file, "%s%u%s%u%s%u%s", "Circle: \n X: ", circle.center.x, "\n Y: ", circle.center.y, "\n Radius: ", circle.radius, "\n");
}

Circle GenerateCircle()
{
    srand(time(0));
    Circle circle;
    circle.center.x = rand() % 101;
    circle.center.y = rand() % 101;
    circle.radius = rand() % 21;
    return circle;
}

Circle ReadCircle(FILE* file)
{
    int x, y, radius;
    fscanf(file, "%u%u%u", &x, &y, &radius);
    Circle circle;
    circle.center.x = x;
    circle.center.y = y;
    circle.radius = radius;
    return circle;
}

