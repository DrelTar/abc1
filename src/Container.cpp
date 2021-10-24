#include "Container.h"
#include "iostream"
#include "stdlib.h"
#include "time.h"

Container::Container() {}

void Container::InclusionSort() {
    for (int i = 1; i < length; i++) {
        Figure* cur = figures[i];
        int ind = i;
        while (ind > 0 && (*figures[ind - 1]).Area() >= (*cur).Area()) {
            figures[ind] = figures[ind - 1];
            ind -= 1;
        }
        figures[ind] = cur;
    }
}

int Container::FillContainer(int argc, char* argv[]) {
    if (argc < 2 || argc > 3) {
        printf("%s", "Incorrect amount of arguments.");
        return 1;
    }
    length = atoi(argv[1]);
    if (argc == 3) {
        FILE* file;
        if (length < 0 || length > 20) {
            printf("%s", "Incorrect amount of figures for this test.");
            return 1;
        }
        file = fopen(argv[2], "rt");
        for (int i = 0; i < length; i += 1) {
            int type;
            fscanf(file, "%u", &type);
            if (type == 1) {
                figures[i] = new Circle();
                (*figures[i]).Read(file);
            }
            else if (type == 2) {
                figures[i] = new Rectangle();
                (*figures[i]).Read(file);
            }
            else if (type == 3) {
                figures[i] = new Triangle();
                (*figures[i]).Read(file);
            }
            else {
                printf("%s", "Wrong type of figure at input file.");
                return 1;
            }
        }
        fclose(file);
    }
    else if (argc == 2) {
        if (length < 20 || length > 100000) {
            printf("%s", "Incorrect amount of figures for this test.");
            return 1;
        }
        srand(time(0));
        for (int i = 0; i < length; i += 1) {
            int type = rand() % 3;
            if (type == 0) {
                figures[i] = new Circle();
                (*figures[i]).Generate();
            }
            else if (type == 1) {
                figures[i] = new Rectangle();
                (*figures[i]).Generate();
            }
            else if (type == 2) {
                figures[i] = new Triangle();
                (*figures[i]).Generate();
            }
        }
    }
    return 0;
}

Container::~Container() {
    delete[] figures;
}
