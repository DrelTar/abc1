#include "Rectangle.h"
#include "stdlib.h"
#include "time.h"

Rectangle::Rectangle()
{
    leftTop = {0, 1};
    rightBottom = {1, 0};
}

double Rectangle::Area() {
    return abs(leftTop.x - rightBottom.x) * abs(leftTop.y - rightBottom.y);
}

void Rectangle::Display(FILE* file) {
    fprintf(file, "%s%u%s%u%s%u%s%u%s", "Rectangle: \n Left Top X: ", leftTop.x, "\n Left Top Y: ", leftTop.y,
             "\n Right Bottom X: ", rightBottom.x, "\n Right Bottom Y: ", rightBottom.y, "\n");
}

void Rectangle::Generate() {
    srand(time(0));
    leftTop.x = rand() % 101;
    leftTop.y = rand() % 101;
    rightBottom.x = rand() % 101;
    rightBottom.y = rand() % 101;
}

void Rectangle::Read(FILE* file) {
    int leftTopX, leftTopY, rightBottomX, rightBottomY;
    fscanf(file, "%u%u%u%u", &leftTopX, &leftTopY, &rightBottomX, &rightBottomY);
    leftTop.x = leftTopX;
    leftTop.y = leftTopY;
    rightBottom.x = rightBottomX;
    rightBottom.y = rightBottomY;
}

Rectangle::~Rectangle()
{
    delete &leftTop;
    delete &rightBottom;
}
