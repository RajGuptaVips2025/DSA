//printing the address of the array
#include <iostream>
#include <stdio.h>
using namespace std;

int main() {
    // C-style arrays
    int A[5];
    int B[5] = {1, 2, 3, 4, 5};
    int C[10] = {2, 4, 6};
    int D[5] = {0};
    int E[] = {1, 2, 3, 4, 5, 6};

    // C-style printing of memory addresses
    for (int i = 0; i < 5; i++) {
        printf("C-style: Address of A[%u] = %u\n", i, &A[i]);
        // %u is used for printing the address in C code 
        cout << "C++-style: Address of A[" << i << "] = " << &A[i] << endl;
    }

    return 0;
}