// Diagonal Matrix

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

struct Matrix{
    int* A;
    int n;
};

void setMatrix(struct Matrix *m, int i, int j, int x){
    if (i==j){
        m->A[i-1]=x;
    }
}

int getMatrix(struct Matrix *m, int i, int j){
    if (i==j){
        return m->A[i-1];
    }
    else{
        return 0;
    }
}

void Display(struct Matrix *m){
    for (int i = 0; i < m->n; i++){
        for (int j = 0; j < m->n; j++){
            if (i==j){
                printf("%d ", m->A[i]);
            }
            else{
                printf("0 ");
            }
        } 
        printf("\n"); 
    }
}

int main() {
    struct Matrix m;
    m.n = 5; // size of the array
    m.A = (int*)malloc(m.n * sizeof(int)); // C-style dynamic allocation

    setMatrix(&m,1,1,5);
    setMatrix(&m,2,2,6);
    setMatrix(&m,3,3,7);
    setMatrix(&m,4,4,8);
    setMatrix(&m,5,5,9);
    

    Display(&m);

    return 0;
}