#include "Circle.h"
#include "Rectangle.h"
#include "Triangle.h"
#ifndef CONTAINER_H
#define CONTAINER_H

class Container {
public:
    Figure* figures[10000];
    int length = 0;
    void InclusionSort();
    int FillContainer(int argc, char* argv[]);
    Container();
    ~Container();
};

#endif // CONTAINER_H
