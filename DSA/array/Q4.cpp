#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

int main() {
    // Static 2D array (allocated on stack)
    int A[3][4] = {
        {1, 2, 3, 4},
        {2, 4, 6, 8},
        {1, 3, 5, 7}
    };

    // Array of 3 int pointers (each pointer will point to a dynamic array of 4 integers)
    int* B[3];

    // Double pointer for dynamic 2D array
    int** C;

    // Dynamically allocate memory for B arrays (each of 4 integers)
    B[0] = (int*)malloc(4 * sizeof(int));
    B[1] = (int*)malloc(4 * sizeof(int));
    B[2] = (int*)malloc(4 * sizeof(int));

    // Dynamically allocate memory for C
    // First, allocate array of 3 pointers
    C = (int**)malloc(3 * sizeof(int*));

    // Now, for each pointer, allocate memory for 4 integers
    C[0] = (int*)malloc(4 * sizeof(int));
    C[1] = (int*)malloc(4 * sizeof(int));
    C[2] = (int*)malloc(4 * sizeof(int));

    // Print elements of static array A
    printf("Array A \n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }

    printf("\n");

    // Print elements of dynamic array B (currently uninitialized, will print garbage values)
    printf("Array B \n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%d ", B[i][j]);
        }
        printf("\n");
    }

    printf("\n");

    // Print elements of dynamic array C (currently uninitialized, will print garbage values)
    printf("Array C \n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }

    // Free the dynamically allocated memory for B
    for (int i = 0; i < 3; i++) {
        free(B[i]);
    }

    // Free the dynamically allocated memory for C
    for (int i = 0; i < 3; i++) {
        free(C[i]);
    }
    free(C); // Free the array of pointers itself

    return 0;
}
