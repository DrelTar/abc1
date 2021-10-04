#include "Enums.h"
#include "stdio.h"
#include "Structs.h"
#ifndef FIGURE_H
#define FIGURE_H

class Figure
{
    public:
        Color color;
        virtual double Square();
        virtual void Display(FILE* file);
        Figure();
        virtual ~Figure();
};

#endif // FIGURE_H
