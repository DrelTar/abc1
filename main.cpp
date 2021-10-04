#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <Circle.h>
#include <Rectangle.h>
#include <Triangle.h>

void inclusionSort(Figure *arr, int length)
{
    for (int i = 1; i < length; i++)
    {
        Figure cur = arr[i];
        int ind = i;
        while (ind > 0 && arr[ind - 1].Square() >= cur.Square())
        {
            arr[ind] = arr[ind - 1];
            ind -= 1;
        }
        arr[ind] = cur;
    }
}

int main(int argc, char* argv[])
{
    FILE *file;
    if (argc < 2 || argc > 3)
    {
        printf("%s", "Incorrect amount of arguments.");
        exit(1);
    }
    int amount = atoi(argv[1]);
    Figure *arr[amount];
    Figure *input[amount];
    if (argc == 3) {
        if (amount < 0 || amount > 20) {
            printf("%s", "Incorrect amount of figures for this test.");
            exit(1);
        }
        file = fopen(argv[2], "rt");
        for (int i = 0; i < amount; i += 1) {
            int type;
            fscanf(file, "%u", &type);
            if (type == 1) {
                int x, y, radius;
                fscanf(file, "%u%u%u", &x, &y, &radius);
                arr[i] = new Circle(x, y, radius);
                input[i] = arr[i];
            }
            else if (type == 2) {
                int leftTopX, leftTopY, rightBottomX, rightBottomY;
                fscanf(file, "%u%u%u%u", &leftTopX, &leftTopY, &rightBottomX, &rightBottomY);
                arr[i] = new Rectangle(leftTopX, leftTopY, rightBottomX, rightBottomY);
                input[i] = arr[i];
            }
            else if (type == 3) {
                int firstX, firstY, secondX, secondY, thirdX, thirdY;
                fscanf(file, "%u%u%u%u%u%u", &firstX, &firstY, &secondX, &secondY, &thirdX, &thirdY);
                arr[i] = new Triangle(firstX, firstY, secondX, secondY, thirdX, thirdY);
                input[i] = arr[i];
            }
            else {
                printf("%s", "Wrong type of figure at input file.");
                exit(1);
            }
        }
        fclose(file);
    }
    else if (argc == 2)
    {
        if (amount < 20 || amount > 100000)
        {
            printf("%s", "Incorrect amount of figures for this test.");
            exit(1);
        }
        srand(time(0));
        for (int i = 0; i < amount; i += 1) {
            int type = rand() % 3;
            if (type == 0) {
                arr[i] = new Circle(rand() % 101, rand() % 101, rand() % 21);
                input[i] = arr[i];
            }
            else if (type == 1)
            {
                int lx = rand() % 101, ry = rand() % 101;
                arr[i] = new Rectangle(lx, rand() % 101 + ry, rand() % 101 + lx, ry);
                input[i] = arr[i];
            }
            else if (type == 2)
            {
                arr[i] = new Triangle(rand() % 101, rand() % 101, rand() % 101, rand() % 101, rand() % 101, rand() % 101);
                input[i] = arr[i];
            }
        }
    }
    for (int i = 1; i < amount; i++)
    {
        Figure *cur = arr[i];
        int ind = i;
        while (ind > 0 && (*arr[ind - 1]).Square() >= (*cur).Square())
        {
            arr[ind] = arr[ind - 1];
            ind -= 1;
        }
        arr[ind] = cur;
    }
    file = fopen("../../outputs/output.txt", "w");
    for (int i = 0; i < amount; ++i) {
        (*input[i]).Display(file);
    }
    fprintf(file, "%s%u%s", "\n\n", amount, "\n\n\n");
    for (int i = 0; i < amount; ++i) {
        (*arr[i]).Display(file);
    }
    return 0;
}
