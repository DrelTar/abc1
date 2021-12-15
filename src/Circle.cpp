#include "Circle.h"
#include "math.h"
#include "stdlib.h"
#include "time.h"
#define _USE_MATH_DEFINES

unsigned int* Circle::seed;

double Area(Circle circle)
{
    return M_PI * double(circle.radius) * double(circle.radius);
}

void* DisplayCircle(void* circle)
{
    Circle* cir = static_cast<Circle*>(circle);
    fprintf(cir->output_file, "%s%u%s%u%s%u%s", "Circle: \n X: ", cir->center.x,
            "\n Y: ", cir->center.y, "\n Radius: ", cir->radius, "\n");
}

void* GenerateCircle(void* circle)
{
    Circle* cir = static_cast<Circle*>(circle);
    srand(time(0));
    unsigned int tmp = rand();
    cir->seed = &tmp;
    cir->center.x = rand_r(cir->seed) % 101;
    tmp = rand_r(cir->seed);
    cir->seed = &tmp;
    cir->center.y = rand_r(cir->seed) % 101;
    tmp = rand_r(cir->seed);
    cir->seed = &tmp;
    cir->radius = rand_r(cir->seed) % 21;
    tmp = rand_r(cir->seed);
    cir->seed = &tmp;
}

void* ReadCircle(void* circle)
{
    Circle* cir = static_cast<Circle*>(circle);
    int x, y, radius;
    fscanf(cir->input_file, "%u%u%u", &x, &y, &radius);
    cir->center.x = x;
    cir->center.y = y;
    cir->radius = radius;
}

