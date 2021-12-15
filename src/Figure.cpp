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

void* DisplayFigure(void* figure)
{
    Figure* fig = static_cast<Figure*>(figure);
    if (fig->type == circleType) {
        DisplayCircle(&fig->circle);
    }
    else if (fig->type == rectangleType) {
        DisplayRectangle(&fig->rectangle);
    }
    else if (fig->type == triangleType) {
        DisplayTriangle(&fig->triangle);
    }
}
