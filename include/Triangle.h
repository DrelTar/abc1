#include "Figure.h"
#ifndef TRIANGLE_H
#define TRIANGLE_H


class Triangle : public Figure
{
    public:
        Point first;
        Point second;
        Point third;
        double Square() override;
        void Display(FILE* file) override;
        Triangle(int firstX, int firstY, int secondX, int secondY, int thirdX, int thirdY);
        Triangle();
        ~Triangle();
};

#endif // TRIANGLE_H
