#include "Container.h"
#include "stdio.h"
#include "pthread.h"

int main(int argc, char* argv[])
{
    Container container;
    pthread_t thread;
    if (FillContainer(container, argc, argv)) {
        return 1;
    }
    FILE* file = fopen("../output.txt", "w");
    for (int i = 0; i < container.length; ++i) {
        if (container.figures[i].type == circleType) {
            container.figures[i].circle.output_file = file;
        } else if (container.figures[i].type == rectangleType) {
            container.figures[i].rectangle.output_file = file;
        } else if (container.figures[i].type == triangleType) {
            container.figures[i].triangle.output_file = file;
        }
        pthread_create(&container.figures[i].thread, NULL, DisplayFigure, &container.figures[i]);
    }
    for (int i = 0; i < container.length; ++i) {
        pthread_join(container.figures[i].thread, NULL);
    }
    fprintf(file, "%s%u%s", "\n\n", container.length, "\n\n\n");
    InclusionSort(container);
    for (int i = 0; i < container.length; ++i) {
        pthread_create(&container.figures[i].thread, NULL, DisplayFigure, &container.figures[i]);
    }
    for (int i = 0; i < container.length; ++i) {
        pthread_join(container.figures[i].thread, NULL);
    }
    fclose(file);
    return 0;
}
