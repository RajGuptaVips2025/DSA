// this code is for reversing the array;
/* 
    There are methods for reversing the array.
    1. one is using an auxillary array or we call temporary array.
    2. swapping the elements from last to first or first to last.
    3. left shift and rotate.
*/

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
    printf("\nElements are\n");
    for (int i = 0; i < arr.length; i++)
    {
        printf("%d ", arr.A[i]);
    }
}

void swap(int *x, int *y){
    int temp;
    temp=*x;
    *x=*y;
    *y=temp;
}

void auxReverse(struct Array *arr){
    int *B;

    B = (int *)malloc(arr->length*sizeof(int));
    for (int i = arr->length-1,j=0; i>=0; i--, j++){
        B[j]=arr->A[i];
    }
    for (int i = 0; i < arr->length; i++){
        arr->A[i]=B[i];
    }    
}

void swapReverse(struct Array *arr){
    for (int i = 0, j=arr->length-1; i < j; i++, j--){
        swap(&arr->A[i], &arr->A[j]);
    }    
}

int main() {
    struct Array arr = {{2, 3, 4, 5, 6}, 10, 5};

    // auxReverse(&arr);
    swapReverse(&arr);
    Display(arr);
    return 0;
}