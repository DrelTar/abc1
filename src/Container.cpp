#include "Container.h"
#include "stdlib.h"
#include "time.h"

void InclusionSort(Container &container)
{
    for (int i = 1; i < container.length; i++)
    {
        Figure cur = container.figures[i];
        int ind = i;
        while (ind > 0 && Area(container.figures[ind - 1]) >= Area(cur))
        {
            container.figures[ind] = container.figures[ind - 1];
            ind -= 1;
        }
        container.figures[ind] = cur;
    }
}

int FillContainer(Container &container, int argc, char* argv[])
{
    if (argc < 2 || argc > 3)
    {
        printf("%s", "Incorrect amount of arguments.");
        return 1;
    }
    container.length = atoi(argv[1]);
    if (argc == 3) {
        FILE* file;
        if (container.length < 0 || container.length > 20) {
            printf("%s", "Incorrect amount of figures for this test.");
            return 1;
        }
        file = fopen(argv[2], "rt");
        for (int i = 0; i < container.length; i += 1) {
            int type;
            fscanf(file, "%u", &type);
            if (type == 1) {
                container.figures[i].circle = ReadCircle(file);
                container.figures[i].type = circleType;
            }
            else if (type == 2) {
                container.figures[i].rectangle = ReadRectangle(file);
                container.figures[i].type = rectangleType;
            }
            else if (type == 3) {
                container.figures[i].triangle = ReadTriangle(file);
                container.figures[i].type = triangleType;
            }
            else {
                printf("%s", "Wrong type of figure at input file.");
                return 1;
            }
        }
        fclose(file);
    }
    else if (argc == 2)
    {
        if (container.length < 20 || container.length > 100000)
        {
            printf("%s", "Incorrect amount of figures for this test.");
            return 1;
        }
        srand(time(0));
        for (int i = 0; i < container.length; i += 1) {
            int type = rand() % 3;
            if (type == 0) {
                container.figures[i].circle = GenerateCircle();
                container.figures[i].type = circleType;
            }
            else if (type == 1)
            {
                container.figures[i].rectangle = GenerateRectangle();
                container.figures[i].type = rectangleType;
            }
            else if (type == 2)
            {
                container.figures[i].triangle = GenerateTriangle();
                container.figures[i].type = triangleType;
            }
        }
    }
    return 0;
}
