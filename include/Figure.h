#include "Enums.h"
#include "stdio.h"
#ifndef FIGURE_H
#define FIGURE_H

class Figure
{
public:
    Color color;
    virtual double Area();
    virtual void Display(FILE* file);
    virtual void Generate();
    virtual void Read(FILE* file);
    Figure();
    virtual ~Figure();
};

#endif // FIGURE_H
