#include "Figure.h"

double Area(Figure figure)
{
    if (figure.type == circleType) {
       return Area(figure.circle);
    }
    else if (figure.type == rectangleType) {
        return Area(figure.rectangle);
    }
    else if (figure.type == triangleType) {
        return Area(figure.triangle);
    }
    return 0.0;
}

void Display(Figure figure, FILE* file)
{
    if (figure.type == circleType) {
        Display(figure.circle, file);
    }
    else if (figure.type == rectangleType) {
        Display(figure.rectangle, file);
    }
    else if (figure.type == triangleType) {
        Display(figure.triangle, file);
    }
}
