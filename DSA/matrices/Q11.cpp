// Sparse Matrix using Array of Structures (Triplet Representation)
// creation, display, and multiplication of sparse matrix

/*
✅ Matrix Multiplication Rules:
1.For two matrices A (m × n) and B (n × p):
    a.The resulting matrix C = A × B will be of size (m × p)
    b.You multiply row of A with column of B
    c.Only perform multiplication when A.cols == B.rows

2.✅Key Concepts for Sparse Multiplication:
    a.Only multiply elements where the column index of A matches the row index of B.
    b.Store the results in triplet format again.
    c.Accumulate values for the same (i, j) in the result matrix.
*/

#include <stdio.h>
#include <stdlib.h>

// Structure to represent a non-zero element
struct Element {
    int i;  // Row index
    int j;  // Column index
    int x;  // Value
};

// Structure to represent the sparse matrix
struct Sparse {
    int m;     // Number of rows
    int n;     // Number of columns
    int num;   // Number of non-zero elements
    struct Element *ele;  // Array of non-zero elements
};

// Function to create a sparse matrix
void create(struct Sparse *s) {
    printf("Enter Dimensions (rows and columns): ");
    scanf("%d%d", &s->m, &s->n);

    printf("Enter number of non-zero elements: ");
    scanf("%d", &s->num);

    s->ele = (struct Element *)malloc(s->num * sizeof(struct Element));

    printf("Enter non-zero elements (row column value):\n");
    for (int i = 0; i < s->num; i++) {
        scanf("%d%d%d", &s->ele[i].i, &s->ele[i].j, &s->ele[i].x);
    }

    // Sort the elements by row index first, then by column index
    for (int i = 0; i < s->num - 1; i++) {
        for (int j = i + 1; j < s->num; j++) {
            if (s->ele[i].i > s->ele[j].i ||
               (s->ele[i].i == s->ele[j].i && s->ele[i].j > s->ele[j].j)) {
                // Swap elements
                struct Element temp = s->ele[i];
                s->ele[i] = s->ele[j];
                s->ele[j] = temp;
            }
        }
    }
}

// Function to display sparse matrix
void display(struct Sparse s) {
    int k = 0;
    for (int i = 0; i < s.m; i++) {
        for (int j = 0; j < s.n; j++) {
            if (k < s.num && s.ele[k].i == i && s.ele[k].j == j)
                printf("%d ", s.ele[k++].x);
            else
                printf("0 ");
        }
        printf("\n");
    }
}

// Function to multiply two sparse matrices
// Function to multiply two sparse matrices A and B
struct Sparse multiply(struct Sparse *A, struct Sparse *B) {
    struct Sparse result;

    // Step 1: Set dimensions of result matrix (A.m × B.n)
    result.m = A->m;
    result.n = B->n;
    result.num = 0;  // Initially no non-zero elements in result

    // Step 2: Allocate memory for result matrix
    // Maximum possible non-zero elements = A.num × B.num (worst case)
    result.ele = (struct Element *)malloc(A->num * B->num * sizeof(struct Element));

    // Step 3: Check if multiplication is valid (columns of A == rows of B)
    if (A->n != B->m) {
        printf("Invalid dimensions for multiplication\n");
        result.m = result.n = result.num = 0;
        return result; // Return an empty result
    }

    int k = 0; // Index to track number of non-zero entries in result

    // Step 4: Multiply each element of A with each element of B
    for (int i = 0; i < A->num; i++) {
        for (int j = 0; j < B->num; j++) {

            // Check if A[i].j == B[j].i → only then we can multiply
            if (A->ele[i].j == B->ele[j].i) {

                // Find position (row, col) in the result matrix
                int row = A->ele[i].i;
                int col = B->ele[j].j;

                // Multiply the values of A and B
                int val = A->ele[i].x * B->ele[j].x;

                // Step 5: Check if (row, col) already exists in result
                int found = 0;
                for (int z = 0; z < k; z++) {
                    if (result.ele[z].i == row && result.ele[z].j == col) {
                        // If entry exists, accumulate the value
                        result.ele[z].x += val;
                        found = 1;
                        break;
                    }
                }

                // Step 6: If (row, col) not found, insert as new element
                if (!found) {
                    result.ele[k].i = row;
                    result.ele[k].j = col;
                    result.ele[k].x = val;
                    k++; // Move to next empty index in result.ele
                }
            }
        }
    }

    // Step 7: Update the number of non-zero elements in result matrix
    result.num = k;

    // Step 8: Return the resulting sparse matrix
    return result;
}


// Main function
int main() {
    struct Sparse A, B, C;

    printf("Enter first matrix:\n");
    create(&A);

    printf("Enter second matrix:\n");
    create(&B);

    printf("First Matrix:\n");
    display(A);

    printf("Second Matrix:\n");
    display(B);

    C = multiply(&A, &B);

    printf("Product Matrix:\n");
    display(C);

    // Free allocated memory
    free(A.ele);
    free(B.ele);
    free(C.ele);

    return 0;
}
