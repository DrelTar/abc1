#include "Circle.h"
#include "math.h"
#include "time.h"
#include "stdlib.h"
#define _USE_MATH_DEFINES

Circle::Circle()
{
    center = {0, 0};
    radius = 1;
}

double Circle::Area() {
    return M_PI * double(radius) * double(radius);
}

void Circle::Display(FILE* file) {
    fprintf(file, "%s%u%s%u%s%u%s", "Circle: \n X: ", center.x, "\n Y: ", center.y, "\n Radius: ", radius, "\n");
}

void Circle::Generate() {
    srand(time(0));
    center.x = rand() % 101;
    center.y = rand() % 101;
    radius = rand() % 21;
}

void Circle::Read(FILE* file) {
    int x, y, rad;
    fscanf(file, "%u%u%u", &x, &y, &rad);
    center.x = x;
    center.y = y;
    radius = rad;
}

Circle::~Circle()
{
    delete &center;
    delete &radius;
}
