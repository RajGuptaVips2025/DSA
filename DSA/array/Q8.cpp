// Linear Search Problem.
// the code of C and C++ in this veru similiar that is why there is almost no seapartion of the code in that.

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

struct Array
{
    int A[10];
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


int LinearSearch(struct Array *arr, int key){
    int i;
    for ( i = 0; i < arr->length; i++)
    {
        if (key == arr->A[i])
        {
            return i;
        }
    }
    return -1;
}

int main() {
    struct Array arr = {{2, 3, 4, 5, 6}, 10, 5};

    printf("%d\n", LinearSearch(&arr, 13));
    Display(arr);
    return 0;
}