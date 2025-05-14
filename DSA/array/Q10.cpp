// this code is for doing basic application of Get(), Set(), Max(), Min(), Sum(), Avg() on array;

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

int Get(struct Array *arr, int index){
    if (index>=0 && index<arr->length){
        return arr->A[index];
    }
    else{
        return -1;
    }
}

int Set(struct Array *arr, int index, int x){
    if (index>=0 && index<arr->length){
        arr->A[index] = x;
    }
}

int Max(struct Array *arr){
    int max = arr->A[0];
    for (int i = 0; i < arr->length-1; i++){
        if (arr->A[i]>max){
            max=arr->A[i];
        } 
    }
    return max;
}

int Min(struct Array *arr){
    int min = arr->A[0];
    for (int i = 0; i < arr->length-1; i++){
        if (arr->A[i]<min){
            min=arr->A[i];
        } 
    }
    return min;
}

int Sum(struct Array *arr){
    int sum = 0;
    for (int i = 0; i < arr->length; i++){
        sum += arr->A[i];
    }
    return sum;    
}

float Avg(struct Array *arr){
    return (float)Sum(arr)/arr->length;
}

int main() {
    struct Array arr = {{2, 3, 4, 5, 6}, 10, 5};

    printf("%d\n", Get(&arr,4));
    Set(&arr, 3, 10);
    // printf("The maximum value in the array is: %d\n", Max(&arr));
    cout<<"The maximum value in the array is: "<< Max(&arr) <<endl;
    cout<<"The minimum value in the array is: "<< Min(&arr) <<endl;
    cout<<"The sum of all value in the array is: "<< Sum(&arr) <<endl;
    cout<<"The Average of all value in the array is: "<< Avg(&arr) <<endl;
    Display(arr);
    return 0;
}