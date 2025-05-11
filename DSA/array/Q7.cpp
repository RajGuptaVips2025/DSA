// Deleting the value from a given index.
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

int Delete(struct Array *arr, int index){
    int x = 0;
    // Putting checkpoint and veriing if the index is valid or not.
    if (index>=0 && index<arr->length)
    {
        x = arr->A[index];
        // Start shifting elements from the deletion index.
        for (int i = index; i < arr->length-1; i++)
        {
            arr->A[i] = arr->A[i+1];
        }  
        arr->length--; // decreasing the length of the array after the deletion of the value at the given index.
        return x;
    } 
    return 0;
}

int main() {
    struct Array arr = {{2, 3, 4, 5, 6}, 10, 5};

    printf("%d\n", Delete(&arr, 3));
    Display(arr);
    return 0;
}