#include "Container.h"
#include "stdio.h"

int main(int argc, char* argv[])
{
    FILE* file;
    Container container;
    if (FillContainer(container, argc, argv)) {
        return 1;
    }
    file = fopen("../../outputs/output.txt", "w");
    for (int i = 0; i < container.length; ++i) {
         Display(container.figures[i], file);
    }
    fprintf(file, "%s%u%s", "\n\n", container.length, "\n\n\n");
    InclusionSort(container);
    for (int i = 0; i < container.length; ++i) {
        Display(container.figures[i], file);
    }
    fclose(file);
    return 0;
}
