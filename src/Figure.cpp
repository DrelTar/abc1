#include "Figure.h"

Figure::Figure() {
    color = red;
}

double Figure::Area() {
    return 0.0;
}

void Figure::Display(FILE* file) {
    return;
}

void Figure::Generate() {
    return;
}

void Figure::Read(FILE* file) {
    return;
}

Figure::~Figure() {
    delete &color;
}
