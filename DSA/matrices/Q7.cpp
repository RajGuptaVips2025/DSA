// Tri-Diagonal Matrix

/*
1. A tri-diagonal matrix in Data Structures and Algorithms (DSA) is a special type of sparse matrix that has non-zero elements only on the main diagonal, the diagonal just above it, and the diagonal just below it.
2. Structure of a Tri-Diagonal Matrix:
    For an n × n matrix A, it is tri-diagonal if:
    a. Main Diagonal; i-j = 0
    b. Lower Diagonal; i-j = 1
    c. upper Diagonal; i-j = -1f
3. M[i, j] = non-zero; if |i-j| <= 1
4. M[i, j] = zer0; if |i-j| > 1
5. A tri-diagonal matrix is only contains 3n-2 non-zero elements for a size n matrix.

6. Example of a 5x5 Tri-Diagonal Matrix:(visualization)
    [ a  b  0  0  0 ]
    [ c  d  e  0  0 ]
    [ 0  f  g  h  0 ]
    [ 0  0  i  j  k ]
    [ 0  0  0  l  m ]

7. Index mapping logic
    a. Lower diagonal : condition(i - j == 1) , Formula(T[i - 2])
    b. Main diagonal : condition(i == j) , Formula(T[n - 1 + i - 1])
    c. Upper diagonal : condition(i - j == -1) , Formula(T[2n - 1 + i - 1])

8. 1D array T (size = 3n - 2 = 13):
    T = [c, f,  i,  l, a, d, g,  j, m,  b, e,  h, k]
        ⬆️ ⬆️ ⬆️ ⬆️ ⬆️ ⬆️ ⬆️ ⬆️ ⬆️ ⬆️ ⬆️ ⬆️ ⬆️
        l1 l2  l3  l4  m1 m2  m3 m4 m5  u1 u2  u3 u4       
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
    if (i - j == 1) {
        // Lower diagonal
        m->A[i - 2] = x;
    } else if (i == j) {
        // Main diagonal
        m->A[m->n - 1 + i - 1] = x;
    } else if (i - j == -1) {
        // Upper diagonal
        m->A[2 * m->n - 1 + i - 1] = x;
    }
    // else ignore as it's zero
}

// Get value at (i, j)
int getMatrix(struct Matrix* m, int i, int j) {
    if (i - j == 1) {
        return m->A[i - 2]; // Lower
    } else if (i == j) {
        return m->A[m->n - 1 + i - 1]; // Main
    } else if (i - j == -1) {
        return m->A[2 * m->n - 1 + i - 1]; // Upper
    } else {
        return 0; // Zero otherwise
    }
}

// Display the matrix
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

    // Allocate memory for 3n - 2 elements
    m.A = (int*)malloc((3 * m.n - 2) * sizeof(int));

    printf("Enter all non-zero elements:\n");
    for (int i = 1; i <= m.n; i++) {
        for (int j = 1; j <= m.n; j++) {
            int x;
            scanf("%d", &x);
            setMatrix(&m, i, j, x);
        }
    }

    printf("\nMatrix is:\n");
    Display(&m);

    free(m.A);
    return 0;
}
