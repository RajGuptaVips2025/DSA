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

int primaryMissingElement(struct Array *arr, int n){
    // n here represent the last element of the array
    int sum = 0; // sum represent the sum of elements of array
    for (int i = 0; i < arr->length; i++){
        sum = sum + arr->A[i];
    }
    int s = n*(n+1)/2; // s represent the sum of n values by putting the last value in this formula.
    return s-sum;
}

int secondaryMissingElement(struct Array *arr){
    // this function is for the array when elements are not staring from 1 but are arranged in sorted order.
    // the logic is that in such case the difference of element and index is used to find the missing element
    int low = arr->A[0];
    int diff = low - 0; // low refers to first element and high refers to last element.
    for (int i = 0; i < arr->length; i++){
        if (arr->A[i]-i != diff){
           return i + diff;  // Return directly when found
        } 
    }
    return -1; // Return -1 if no missing element found
}

int main()
{
    struct Array arr = {{6, 7, 8, 10, 11, 12}, 10, 6};

    printf("%d", secondaryMissingElement(&arr));
    return 0;
}