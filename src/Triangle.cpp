#include "Triangle.h"
#include "math.h"
#include "stdio.h"

Triangle::Triangle()
{
    first = {0, 0};
    second = {1, 0};
    third = {0, 1};
}

Triangle::Triangle(int firstX, int firstY, int secondX, int secondY, int thirdX, int thirdY)
{
    first = {firstX, firstY};
    second = {secondX, secondY};
    third = {thirdX, thirdY};
}

double Triangle::Square()
{
    double lengthA = sqrt((second.x - first.x) * (second.x - first.x) + (second.y - first.y) * (second.y - first.y));
    double lengthB = sqrt((third.x - first.x) * (third.x - first.x) + (third.y - first.y) * (third.y - first.y));
    double lengthC = sqrt((second.x - third.x) * (second.x - third.x) + (second.y - third.y) * (second.y - third.y));
    double p = (lengthA + lengthB + lengthC) / 2;
    return sqrt(p * (p - lengthA) * (p - lengthB) * (p - lengthC));
}

void Triangle::Display(FILE* file)
{
    fprintf(file, "%s%u%s%u%s%u%s%u%s%u%s%u%s", "Triangle \n First point X: ", first.x, "\n First point Y: ", first.y,
            "\n Second point X: ", second.x, "\n Second point Y: ", second.y, "\n Third point X: ", third.x, "\n Third point Y: ", third.y, "\n");
}

Triangle::~Triangle()
{
    delete &first;
    delete &second;
    delete &third;
}
