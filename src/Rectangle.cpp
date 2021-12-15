#include "Rectangle.h"
#include "stdlib.h"
#include "time.h"

unsigned int* Rectangle::seed;

double Area(Rectangle rectangle)
{
    return abs(rectangle.leftTop.x - rectangle.rightBottom.x) * abs(rectangle.leftTop.y - rectangle.rightBottom.y);
}

void* DisplayRectangle(void* rectangle)
{
    Rectangle* rec = static_cast<Rectangle*>(rectangle);
    fprintf(rec->output_file, "%s%u%s%u%s%u%s%u%s", "Rectangle: \n Left Top X: ", rec->leftTop.x,
            "\n Left Top Y: ", rec->leftTop.y, "\n Right Bottom X: ", rec->rightBottom.x,
            "\n Right Bottom Y: ", rec->rightBottom.y, "\n");
}

void* GenerateRectangle(void* rectangle)
{
    Rectangle* rec = static_cast<Rectangle*>(rectangle);
    srand(time(0));
    unsigned int tmp = rand();
    rec->seed = &tmp;
    rec->leftTop.x = rand_r(rec->seed) % 101;
    tmp = rand_r(rec->seed);
    rec->seed = &tmp;
    rec->leftTop.y = rand_r(rec->seed) % 101;
    tmp = rand_r(rec->seed);
    rec->seed = &tmp;
    rec->rightBottom.x = rand_r(rec->seed) % 101;
    tmp = rand_r(rec->seed);
    rec->seed = &tmp;
    rec->rightBottom.y = rand_r(rec->seed) % 101;
    tmp = rand_r(rec->seed);
    rec->seed = &tmp;
}

void* ReadRectangle(void* rectangle)
{
    Rectangle* rec = static_cast<Rectangle*>(rectangle);
    int leftTopX, leftTopY, rightBottomX, rightBottomY;
    fscanf(rec->input_file, "%u%u%u%u", &leftTopX, &leftTopY, &rightBottomX, &rightBottomY);
    rec->leftTop.x = leftTopX;
    rec->leftTop.y = leftTopY;
    rec->rightBottom.x = rightBottomX;
    rec->rightBottom.y = rightBottomY;
}
