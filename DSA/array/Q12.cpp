// this code is for inserting the elements in the sorted array;

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

void swap(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void auxReverse(struct Array *arr)
{
    int *B;

    B = (int *)malloc(arr->length * sizeof(int));
    for (int i = arr->length - 1, j = 0; i >= 0; i--, j++)
    {
        B[j] = arr->A[i];
    }
    for (int i = 0; i < arr->length; i++)
    {
        arr->A[i] = B[i];
    }
}

void swapReverse(struct Array *arr)
{
    for (int i = 0, j = arr->length - 1; i < j; i++, j--)
    {
        swap(&arr->A[i], &arr->A[j]);
    }
}

void InsertSort(struct Array *arr, int x)
{
    int i = arr->length - 1;
    if (arr->length == arr->size)
        return;
    while (i >= 0 && arr->A[i] > x)
    {
        arr->A[i + 1] = arr->A[i];
        i--;
    }
    arr->A[i + 1] = x;
    arr->length++;
}

int isSorted(struct Array *arr){
    for (int i = 0; i < arr->length - 1; i++){
        if (arr->A[i]>arr->A[i+1]){
            return 0;
        }
    }
    return 1;
}

void Rearrange(struct Array *arr){
    // this function rearrange the negatives and positive values of the array on either sides.
    int i, j;
    i = 0;
    j=arr->length-1;

    while (i<j){
        while(arr->A[i]<0)i++;
        while (arr->A[j]>=0)j--;
        if (i<j)swap(&arr->A[i], &arr->A[j]);       
    }
    
}

int main()
{
    struct Array arr = {{2, -3, 10, -13, 17, -8}, 10, 6};

    // InsertSort(&arr, 14);
    // printf("%d \n ", isSorted(&arr));
    Rearrange(&arr);
    Display(arr);
    return 0;
}