// Sparse Matrix using Array of Structures (Triplet Representation)
// creation and display of sparse matrix

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a non-zero element
struct Element {
    int i;  // Row index
    int j;  // Column index
    int x;  // Value at (i, j)
}; // Each Element represents a non-zero entry in the matrix at row i, column j, with value x.

// Structure to represent the sparse matrix
struct Sparse {
    int m;     // Number of rows
    int n;     // Number of columns
    int num;   // Number of non-zero elements
    struct Element *ele;  // Array to store non-zero elements, pointer to array of Element structs.
};

// Function to create a sparse matrix
void create(struct Sparse *s) {
    printf("Enter Dimensions (rows and columns): ");
    scanf("%d%d", &s->m, &s->n);  // Input number of rows and columns

    printf("Enter number of non-zero elements: ");
    scanf("%d", &s->num);  // Input number of non-zero elements

    // Allocate memory to store non-zero elements
    s->ele = (struct Element *)malloc(s->num * sizeof(struct Element));

    // Input all non-zero elements in (row, column, value) format
    printf("Enter non-zero elements (row column value):\n");
    for (int i = 0; i < s->num; i++)
        scanf("%d%d%d", &s->ele[i].i, &s->ele[i].j, &s->ele[i].x);
    /*
    This function does the following:
    1. Takes input for matrix dimensions (m x n).
    2. Takes input for how many non-zero elements are present.
    3. Allocates memory for the non-zero elements.
    4. Accepts input for each non-zero element: row, column, value.
    */
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

// Function to display the sparse matrix in 2D format
void display(struct Sparse s) {
    int k = 0;  // Index for non-zero elements

    // Loop through all positions of the full matrix
    for (int i = 0; i < s.m; i++) {
        for (int j = 0; j < s.n; j++) {
            // If current position matches a non-zero element
            if (k < s.num && i == s.ele[k].i && j == s.ele[k].j)
                printf("%d ", s.ele[k++].x);  // Print non-zero value
            else
                printf("0 ");  // Otherwise, print 0
        }
        printf("\n");  // Newline after each row
    }
}

struct Sparse * add(struct Sparse* s1, struct Sparse* s2) {
    struct Sparse *sum;
    int i, j, k;
    i = j = k = 0;

    // Check if dimensions match
    if (s1->m != s2->m || s1->n != s2->n) {
        printf("Matrices dimensions do not match!\n");
        return NULL;
    }

    sum = (struct Sparse*)malloc(sizeof(struct Sparse));
    sum->ele = (struct Element*)malloc((s1->num + s2->num) * sizeof(struct Element));

    while (i < s1->num && j < s2->num) {
        if (s1->ele[i].i < s2->ele[j].i)
            sum->ele[k++] = s1->ele[i++];
        else if (s1->ele[i].i > s2->ele[j].i)
            sum->ele[k++] = s2->ele[j++];
        else {
            if (s1->ele[i].j < s2->ele[j].j)
                sum->ele[k++] = s1->ele[i++];
            else if (s1->ele[i].j > s2->ele[j].j)
                sum->ele[k++] = s2->ele[j++];
            else {
                // Add values and store one entry
                sum->ele[k] = s1->ele[i];
                sum->ele[k++].x = s1->ele[i++].x + s2->ele[j++].x;
            }
        }
    }

    // Copy any remaining elements
    for (; i < s1->num; i++) sum->ele[k++] = s1->ele[i];
    for (; j < s2->num; j++) sum->ele[k++] = s2->ele[j];

    sum->m = s1->m;
    sum->n = s1->n;
    sum->num = k;

    return sum;
}
/*
1. Takes two sparse matrices s1 and s2.
2. Returns a new sparse matrix that is the sum of the two.
3. Assumes non-zero elements are sorted row-wise and column-wise (which you should maintain in input).
4. Loops through both ele[] arrays:
    a.If position of s1 is before s2, copy s1's element.
    b.If position of s2 is before s1, copy s2's element.
    c.If they are at same position, add their x values and store as one element.
5. Adds remaining unmatched elements from either matrix.
*/


// Main function to execute the program
int main() {
    struct Sparse s1, s2, *s3;   // Declare sparse matrix
    create(&s1);
    create(&s2);

    s3=add(&s1,&s2);
    printf("First Matrix\n");
    display(s1);
    printf("second Matrix\n");
    display(s2);
    printf("sum Matrix\n");
    display(*s3); // dereferencing the pointer to pass the actual struct


    return 0;
}
