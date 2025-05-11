// static vs dynamic array

#include <iostream>
#include<stdlib.h>
using namespace std;

int main() {
    int A[5] = {2, 4, 6, 8, 10};
    int *p;
    int *q;
    // C-style dynamic array allocation using malloc keyword
    p = (int *)malloc(5*sizeof(int));
    p[0]=3;
    p[1]=5;
    p[2]=7;
    p[3]=9;
    p[4]=11;
    // C++-style dynamic array allocation using new keyword
    q = new int[5];  // Dynamically allocate array of size 5
    q[0] = 12;
    q[1] = 14;
    q[2] = 16;
    q[3] = 18;
    q[4] = 20;

    for (int i = 0; i < 5; i++)
    {
        printf("C style - %d\n", A[i]);
    }
    printf("\n");
    for (int i = 0; i < 5; i++)
    {
        printf("C style - %d\n", p[i]);
    }
    cout<< "\n" <<endl;
    for (int i = 0; i < 5; i++) {
        // Printing dynamic array allocated with new (q)
        cout << "C++ style (new) - " << q[i] << endl;
    }
    // Free dynamically allocated memory for C-style malloc keyword
    free(p);
    // Free dynamically allocated memory for C++-style new keyword
    delete[] q;

    return 0;
}