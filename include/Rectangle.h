#include "Figure.h"
#ifndef RECTANGLE_H
#define RECTANGLE_H


class Rectangle : public Figure
{
    public:
        Point leftTop;
        Point rightBottom;
        double Square() override;
        void Display(FILE* file) override;
        Rectangle(int a, int b, int c, int d);
        Rectangle();
        ~Rectangle();
};

#endif // RECTANGLE_H
