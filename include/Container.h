#include "Figure.h"
#ifndef CONTAINER_H
#define CONTAINER_H

typedef struct
{
    Figure figures[10000];
    int length;
} Container;

void InclusionSort(Container &container);

int FillContainer(Container &container, int argc, char* argv[]);

#endif // CONTAINER_H
