#include "Rectangle.h"
#include "stdlib.h"
#include "time.h"

double Area(Rectangle rectangle)
{
    return abs(rectangle.leftTop.x - rectangle.rightBottom.x) * abs(rectangle.leftTop.y - rectangle.rightBottom.y);
}

void Display(Rectangle rectangle, FILE* file)
{
    fprintf(file, "%s%u%s%u%s%u%s%u%s", "Rectangle: \n Left Top X: ", rectangle.leftTop.x, "\n Left Top Y: ", rectangle.leftTop.y,
             "\n Right Bottom X: ", rectangle.rightBottom.x, "\n Right Bottom Y: ", rectangle.rightBottom.y, "\n");
}

Rectangle GenerateRectangle()
{
    srand(time(0));
    Rectangle rectangle;
    rectangle.leftTop.x = rand() % 101;
    rectangle.leftTop.y = rand() % 101;
    rectangle.rightBottom.x = rand() % 101;
    rectangle.rightBottom.y = rand() % 101;
    return rectangle;
}

Rectangle ReadRectangle(FILE* file)
{
    int leftTopX, leftTopY, rightBottomX, rightBottomY;
    fscanf(file, "%u%u%u%u", &leftTopX, &leftTopY, &rightBottomX, &rightBottomY);
    Rectangle rectangle;
    rectangle.leftTop.x = leftTopX;
    rectangle.leftTop.y = leftTopY;
    rectangle.rightBottom.x = rightBottomX;
    rectangle.rightBottom.y = rightBottomY;
    return rectangle;
}
