#include "Container.h"
#include "stdio.h"

int main(int argc, char* argv[])
{
    FILE* file;
    Container container;
    if (container.FillContainer(argc, argv)) {
        return 1;
    }
    file = fopen("../../outputs/output.txt", "w");
    for (int i = 0; i < container.length; ++i) {
         (*container.figures[i]).Display(file);
    }
    fprintf(file, "%s%u%s", "\n\n", container.length, "\n\n\n");
    container.InclusionSort();
    for (int i = 0; i < container.length; ++i) {
        (*container.figures[i]).Display(file);
    }
    fclose(file);
    return 0;
}
