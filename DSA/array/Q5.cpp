#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

struct Array
{
    int *A;
    int size;
    int length;
};

void Display(struct Array arr)
{
    int i;
    printf("\n Elements are\n");
    for (int i = 0; i < arr.length; i++)
    {
        printf("%d ", arr.A[i]);
    }
}

int main()
{
    struct Array arr;
    int n; // n is used to represent the number of values to be in an array.

    printf("Enter size of an array:");
    // The ampersand (&) in scanf is used to pass the address of the variable to scanf, so it can modify the value stored at that memory location.
    scanf("%d", &arr.size);
    arr.A = (int *)malloc(arr.size * sizeof(int));
    // Initialize Length
    arr.length = 0;

    printf("Enter number of numbers:");
    scanf("%d", &n);

    printf("Enter all Elements\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr.A[i]);
    }
    arr.length = n;

    Display(arr);

    return 0;
}