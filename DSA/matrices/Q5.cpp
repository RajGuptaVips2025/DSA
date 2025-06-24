// Upper Triangular Matrix(Column-Major)

/*
1. M[i,j] = 0, if i>j
2. M[i,j] = non-zero, if i<=j
3. non-zero = 5+4+3+2+1
    = n+(n-1)+(n-2)+ .... +2+1 = n(n+1)/2
4. zero = n^2-n(n+1)/2 = n(n-1)/2
5. Formula for row major in upper Triangular Matrix 
    =>  [1+2+3+.....+(j-1)] + (i-1)
        [j(j-1)/2 + (i-1)]
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
    if (i <= j){
        int index = (j*(j-1))/2 + (i-1);
        m->A[index] = x;
    }
}

int getMatrix(struct Matrix *m, int i, int j){
    if (i <= j){
        int index = (j*(j-1))/2 + (i-1);
        return m->A[index];
    }
    else{
        return 0;
    }
}

void Display(struct Matrix *m){
    for (int i = 1; i <= m->n; i++){
        for (int j = 1; j <= m->n; j++){
            if (i <= j){
                int index = (j*(j-1))/2 + (i-1);
                printf("%d ", m->A[index]);
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
    
    free(m.A);
    return 0;
}
