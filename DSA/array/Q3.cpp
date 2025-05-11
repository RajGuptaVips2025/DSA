// Increasing the size of an array.

#include <iostream>
#include <stdlib.h>
using namespace std;

int main() {
    int *p, *q;
    int *x, *y;
    p = (int*)malloc(5*sizeof(int));
    p[0] = 2;
    p[1] = 3;
    p[2] = 4;
    p[3] = 5;
    p[4] = 6;

    q = (int*)malloc(5*sizeof(int));
    
    for (int i = 0; i < 5; i++)
    {
        q[i] = p[i];
    }

    x = new int[5];
    x[0] = 2;
    x[1] = 3;
    x[2] = 4;
    x[3] = 5;
    x[4] = 6;

    y = new int[10];

    for (int i = 0; i < 5; i++)
    {
        y[i] = x[i];
    }

    // Free dynamically allocated memory for C-style malloc keyword
    free(p);
    p=q;
    q=NULL;

    delete[] x;
    x=y;
    y=NULL;
    
    for (int i = 0; i < 5; i++)
    {
        printf("C code - %d\n", p[i]);
    }

    for (int i = 0; i < 5; i++)
    {
        cout<< "C++ code - "<< x[i] << endl;
    }

    return 0;
}