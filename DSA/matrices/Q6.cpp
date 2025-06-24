// Symmetric Matrix stored in lower triangular matrix in row major mapping

/*
1. M[i, j] = M[j, i]
*/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

struct Matrix{
    int* A;
    int n;
};

void setMatrix(struct Matrix *m, int i, int j, int x){
    if (i>=j){
        int index = (i - 1) * i / 2 + j;
        m->A[index] = x;
    }
    
}

int getMatrix(struct Matrix* m, int i, int j) {
    if (i >= j) {
        int index = (i - 1) * i / 2 + j;  // 0-based indexing
        return m->A[index];
    } else {
        int index = (j - 1) * j / 2 + i;
        return m->A[index];  // Because it's symmetric
    }
}

void Display(struct Matrix *m){
    for (int i = 1; i <= m->n; i++){
        for (int j = 1; j <= m->n; j++){
            if (i >= j){
                int index = (i - 1) * i / 2 + j;
                printf("%d ", m->A[index]);
            }
            else{
                int index = (j - 1) * j / 2 + i;
                printf("%d ", m->A[index]);
            }
        }
        printf("\n");
    }
}

int main() {
    struct Matrix m;
    int x;

    printf("Enter Dimension \n");
    scanf("%d", &m.n);
    m.A = (int *)malloc((m.n * (m.n + 1) / 2) * sizeof(int));

    printf("Enter all elements \n");
    for (int i = 1; i <= m.n; i++){
        for (int j = 1; j <= m.n; j++){
            scanf("%d", &x);
            setMatrix(&m, i, j, x);
        }
    }

    printf("\nMatrix:\n");
    Display(&m);
    getMatrix(&m,4,1);
    // printf("%d", getMatrix(&m,4,1));
    
    free(m.A);
    return 0;
}
