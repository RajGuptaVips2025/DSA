// Sparse Matrix using Array of Structures (Triplet Representation)
// creation, display, and transpose of sparse matrix

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

// Function to transpose the sparse matrix
struct Sparse* transpose(struct Sparse *s) {
    struct Sparse *t = (struct Sparse *)malloc(sizeof(struct Sparse));
    t->m = s->n;  // Swapping rows and columns
    t->n = s->m;
    t->num = s->num;
    t->ele = (struct Element *)malloc(s->num * sizeof(struct Element));

    int k = 0;

    // For each column j in original, collect elements into t
    for (int col = 0; col < s->n; col++) {
        for (int i = 0; i < s->num; i++) {
            if (s->ele[i].j == col) {
                t->ele[k].i = s->ele[i].j;
                t->ele[k].j = s->ele[i].i;
                t->ele[k].x = s->ele[i].x;
                k++;
            }
        }
    }

    return t;
}

// Main function
int main() {
    struct Sparse s, *st;
    
    create(&s);

    printf("Original Matrix:\n");
    display(s);

    st = transpose(&s);

    printf("Transposed Matrix:\n");
    display(*st);

    // Free memory
    free(s.ele);
    free(st->ele);
    free(st);

    return 0;
}


/*
1. Input Matrix (3×3):
[ 0  5  0 ]
[ 0  0  8 ]
[ 3  0  0 ]


2. Input in Sparse Triplet:
Index	Row (i)	  Col (j) Value (x)
0	      0	        1	    5
1	      1	        2	    8
2	      2	        0	    3

3. 🔄 Transposing Logic
We loop:

for (col = 0; col < 3; col++) {
  for (i = 0; i < 3; i++) {
    if (s->ele[i].j == col) {
      // swap i <-> j
    }
  }
}
Iteration by column:
col = 0 → picks {2, 0, 3} → becomes {0, 2, 3}

col = 1 → picks {0, 1, 5} → becomes {1, 0, 5}

col = 2 → picks {1, 2, 8} → becomes {2, 1, 8}



*/