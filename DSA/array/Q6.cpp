// Appending the code or inserting the value in array in both C and C++.
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

void Append(struct Array *arr, int x){
    if (arr->length<arr->size){
        arr->A[arr->length++] = x;
    }  
}

void Insert(struct Array *arr, int index, int x){
    int i;
    if (index>=0 && index<=arr->length)
    {
        for(i=arr->length; i>index; i--){
            arr->A[i] = arr->A[i-1];
        }
        arr->A[index]=x;
        arr->length++;
    } 
}

int main() {
    struct Array arr = {{2, 3, 4, 5, 6}, 10, 5};

    // Append(&arr, 7);
    Insert(&arr, 2, 10);
    Display(arr);

    return 0;
}