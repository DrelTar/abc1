#include "Triangle.h"
#include "math.h"
#include "time.h"
#include "stdlib.h"

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

void Display(Triangle triangle, FILE* file)
{
    fprintf(file, "%s%u%s%u%s%u%s%u%s%u%s%u%s", "Triangle \n First point X: ", triangle.first.x, "\n First point Y: ", triangle.first.y,
            "\n Second point X: ", triangle.second.x, "\n Second point Y: ", triangle.second.y, "\n Third point X: ", triangle.third.x,
             "\n Third point Y: ", triangle.third.y, "\n");
}

Triangle GenerateTriangle()
{
    srand(time(0));
    Triangle triangle;
    triangle.first.x = rand() % 101;
    triangle.first.y = rand() % 101;
    triangle.second.x = rand() % 101;
    triangle.second.y = rand() % 101;
    triangle.third.x = rand() % 101;
    triangle.third.y = rand() % 101;
    return triangle;
}

Triangle ReadTriangle(FILE* file)
{
    int firstX, firstY, secondX, secondY, thirdX, thirdY;
    fscanf(file, "%u%u%u%u%u%u", &firstX, &firstY, &secondX, &secondY, &thirdX, &thirdY);
    Triangle triangle;
    triangle.first.x = firstX;
    triangle.first.y = firstY;
    triangle.second.x = secondX;
    triangle.second.y = secondY;
    triangle.third.x = thirdX;
    triangle.third.y = thirdY;
    return triangle;
}
