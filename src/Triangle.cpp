#include "Triangle.h"
#include "math.h"
#include "time.h"
#include "stdlib.h"

double Triangle::Area()
{
    double lengthA = sqrt((second.x - first.x) * (second.x - first.x) +
                        (second.y - first.y) * (second.y - first.y));
    double lengthB = sqrt((third.x - first.x) * (third.x - first.x) +
                        (third.y - first.y) * (third.y - first.y));
    double lengthC = sqrt((second.x - third.x) * (second.x - third.x) +
                        (second.y - third.y) * (second.y - third.y));
    double p = (lengthA + lengthB + lengthC) / 2;
    return sqrt(p * (p - lengthA) * (p - lengthB) * (p - lengthC));
}

void Triangle::Display(FILE* file) {
    fprintf(file, "%s%u%s%u%s%u%s%u%s%u%s%u%s", "Triangle \n First point X: ", first.x, "\n First point Y: ", first.y,
            "\n Second point X: ", second.x, "\n Second point Y: ", second.y,
            "\n Third point X: ", third.x, "\n Third point Y: ", third.y, "\n");
}

void Triangle::Generate() {
    srand(time(0));
    first.x = rand() % 101;
    first.y = rand() % 101;
    second.x = rand() % 101;
    second.y = rand() % 101;
    third.x = rand() % 101;
    third.y = rand() % 101;
}

void Triangle::Read(FILE* file) {
    int firstX, firstY, secondX, secondY, thirdX, thirdY;
    fscanf(file, "%u%u%u%u%u%u", &firstX, &firstY, &secondX, &secondY, &thirdX, &thirdY);
    first.x = firstX;
    first.y = firstY;
    second.x = secondX;
    second.y = secondY;
    third.x = thirdX;
    third.y = thirdY;
}
