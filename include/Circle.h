#include "Figure.h"
#include "stdlib.h"
#ifndef CIRCLE_H
#define CIRCLE_H


class Circle : public Figure
{
    public:
        Point center;
        int radius;
        double Square() override;
        void Display(FILE* file) override;
        Circle(int a, int b, int c);
        Circle();
        ~Circle();
};

#endif // CIRCLE_H
