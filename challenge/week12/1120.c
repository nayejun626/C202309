#include <stdio.h>

void printArray(int rows, int **arr, int cols[])
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols[i]; j++)
        {
            printf("%d\n", arr[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int row1[] = {1, 2, 3, 4};
    int row2[] = {5, 6, 7};
    int row3[] = {8, 9, 10, 11, 12};

    int *myArray[] = {row1, row2, row3};

    int cols[] = {4, 3, 5};

    printArray(3, myArray, cols);
    return 0;
}