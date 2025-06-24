// Lower Triangular Matrix (Column-Major)

/*
1. M[i,j] = 0, if i<j
2. M[i,j] = non-zero, if i>=j
3. Non-zero elements = 1+2+3+4+5+ ...... n = n(n+1)/2
4. zero elements = n^2 - n(n+1)/2 = n(n-1)/2
5. Formula for column major Lower Triangular Matrix 
    =>  [n+(n-1)+(n-2)+ .... + n-(j-2)] + (i-j)
        [n(j-1) - (j-2)(j-1)/2]+(i-j)
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
        m->A[m->n*(j-1)+(j-2)*(j-1)/2+(i-j)]=x;
    }
}

int getMatrix(struct Matrix *m, int i, int j){
    if (i>=j){
        return m->A[m->n*(j-1)+(j-2)*(j-1)/2+(i-j)];
    }
    else{
        return 0;
    }
}

void Display(struct Matrix *m){
    for (int i = 1; i <= m->n; i++){
        for (int j = 1; j <= m->n; j++){
            if (i>=j){
                printf("%d ", m->A[m->n*(j-1)+(j-2)*(j-1)/2+(i-j)]);
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
    m.A=(int *)malloc(m.n*(m.n-1)/2*sizeof(int));

    printf("Enter all elements \n");
    for (int i = 1; i <= m.n; i++)
    {
        for (int j = 1; j <= m.n; j++)
        {
            scanf("%d", &x);
            setMatrix(&m, i, j, x);
        }
    }
    printf("\n\n");
    Display(&m);
    
    return 0;
}