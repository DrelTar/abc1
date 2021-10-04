#include "Figure.h"

Figure::Figure()
{
    color = red;
}

double Figure::Square()
{
    return 0.0;
}

void Figure::Display(FILE* file)
{
    return;
}

Figure::~Figure()
{
    delete &color;
}
