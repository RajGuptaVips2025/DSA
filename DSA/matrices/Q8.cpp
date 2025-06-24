// Toeplitz Matrix

/*
1. In DSA (Data Structures and Algorithms), a Toeplitz matrix is a special kind of matrix in which every descending diagonal from left to right is constant.
2. A matrix M is called a Toeplitz Matrix if:
    M[i][j] == M[i-1][j-1]
3. Example of a Toeplitz Matrix:
    [6  7  8  9]
    [4  6  7  8]
    [1  4  6  7]
    [0  1  4  6]
4. It can be stored using only O(m + n - 1) space instead of O(m*n), which is beneficial in memory-constrained environments.
5.  Visualization of Toeplitz Matrix.
    Index:      0   1   2   3   4   5   6
                ⬆️ ⬆️ ⬆️  ⬆️ ⬆️  ⬆️ ⬆️
    Stored:     6   7   8   9   4   1   0
                [row........]   [column..] 
6.  Index mapping logic
    a. Case 1:
        If (i<=j):
            index = (j-i)
    b. Case 2:
        If (i>j):
            index = (n-1)+(i-j)
*/


#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

struct Matrix {
    int* A; // 1D array to store non-zero elements
    int n;  // Dimension of the matrix (n x n)
};

// Set value at (i, j)
void setMatrix(struct Matrix* m, int i, int j, int x) {
    if (i<=j){
        m->A[j - i] = x; // from first row
    }
    else{
        m->A[m->n-1+(i-j)] = x; // from first column
    } 
}

// Get value at (i, j)
int getMatrix(struct Matrix* m, int i, int j) {
    if (i<=j){
        return m->A[j - i]; // from first row
    }
    else{
        return m->A[m->n-1+(i-j)]; // from first column
    } 
}

/// Display the matrix
void Display(struct Matrix* m) {
    for (int i = 1; i <= m->n; i++) {
        for (int j = 1; j <= m->n; j++) {
            printf("%d ", getMatrix(m, i, j));
        }
        printf("\n");
    }
}

int main() {
    struct Matrix m;
    printf("Enter dimension of matrix: ");
    scanf("%d", &m.n);

    // Allocate memory for 2n - 1 elements
    m.A = (int*)malloc((2 * m.n - 1) * sizeof(int));

    printf("Enter elements of first row:\n");
    for (int j = 1; j <= m.n; j++) {
        int x;
        scanf("%d", &x);
        setMatrix(&m, 1, j, x); // first row: i = 1
    }

    printf("Enter elements of first column (excluding first element):\n");
    for (int i = 2; i <= m.n; i++) {
        int x;
        scanf("%d", &x);
        setMatrix(&m, i, 1, x); // first column: j = 1
    }

    printf("\nToeplitz Matrix is:\n");
    Display(&m);

    free(m.A);
    return 0;
}