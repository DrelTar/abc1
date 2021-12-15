#include "Triangle.h"
#include "math.h"
#include "stdlib.h"
#include "time.h"

unsigned int* Triangle::seed;

double Area(Triangle triangle)
{
    double lengthA = sqrt((triangle.second.x - triangle.first.x) * (triangle.second.x - triangle.first.x) +
                        (triangle.second.y - triangle.first.y) * (triangle.second.y - triangle.first.y));
    double lengthB = sqrt((triangle.third.x - triangle.first.x) * (triangle.third.x - triangle.first.x) +
                        (triangle.third.y - triangle.first.y) * (triangle.third.y - triangle.first.y));
    double lengthC = sqrt((triangle.second.x - triangle.third.x) * (triangle.second.x - triangle.third.x) +
                        (triangle.second.y - triangle.third.y) * (triangle.second.y - triangle.third.y));
    double p = (lengthA + lengthB + lengthC) / 2;
    return sqrt(p * (p - lengthA) * (p - lengthB) * (p - lengthC));
}

void* DisplayTriangle(void* triangle)
{
    Triangle* tri = static_cast<Triangle*>(triangle);
    fprintf(tri->output_file, "%s%u%s%u%s%u%s%u%s%u%s%u%s", "Triangle \n First point X: ", tri->first.x,
            "\n First point Y: ", tri->first.y, "\n Second point X: ", tri->second.x,
            "\n Second point Y: ", tri->second.y, "\n Third point X: ", tri->third.x,
            "\n Third point Y: ", tri->third.y, "\n");
}

void* GenerateTriangle(void* triangle)
{
    Triangle* tri = static_cast<Triangle*>(triangle);
    srand(time(0));
    unsigned int tmp = rand();
    tri->seed = &tmp;
    tri->first.x = rand_r(tri->seed) % 101;
    tmp = rand_r(tri->seed);
    tri->seed = &tmp;
    tri->first.y = rand_r(tri->seed) % 101;
    tmp = rand_r(tri->seed);
    tri->seed = &tmp;
    tri->second.x = rand_r(tri->seed) % 101;
    tmp = rand_r(tri->seed);
    tri->seed = &tmp;
    tri->second.y = rand_r(tri->seed) % 101;
    tmp = rand_r(tri->seed);
    tri->seed = &tmp;
    tri->third.x = rand_r(tri->seed) % 101;
    tmp = rand_r(tri->seed);
    tri->seed = &tmp;
    tri->third.y = rand_r(tri->seed) % 101;
    tmp = rand_r(tri->seed);
    tri->seed = &tmp;
    return triangle;
}

void* ReadTriangle(void* triangle)
{
    Triangle* tri = static_cast<Triangle*>(triangle);
    int firstX, firstY, secondX, secondY, thirdX, thirdY;
    fscanf(tri->input_file, "%u%u%u%u%u%u", &firstX, &firstY, &secondX, &secondY, &thirdX, &thirdY);
    tri->first.x = firstX;
    tri->first.y = firstY;
    tri->second.x = secondX;
    tri->second.y = secondY;
    tri->third.x = thirdX;
    tri->third.y = thirdY;
}
