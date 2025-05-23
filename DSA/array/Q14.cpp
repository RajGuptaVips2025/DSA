/*
An array is a data structure that stores elements of the same type in a contiguous block of memory. In an array, , of size , each memory location has some unique index,  (where ), that can be referenced as  or .

Your task is to reverse an array of integers.

Note: If you've already solved our C++ domain's Arrays Introduction challenge, you may want to skip this.

Example

Return .

Function Description

Complete the function  with the following parameter(s):

: the array to reverse
Returns

: the reversed array
Input Format

The first line contains an integer, , the number of integers in .
The second line contains  space-separated integers that make up .

Constraints
1<=N<=10^3
1<=A[i]<=10^4, where A[i] is the ith integer in A
*/

/*
int a_count

This is the number of elements in the input array a.

Think of it as the size of the array.

Example: If the input is 1 2 3 4 5, then a_count is 5.

int* a

This is a pointer to the input array of integers.

It points to the memory location where the original array is stored.

You will use this array to reverse its contents.

int* result_count

This is a pointer to an integer where you will store the size of the result array (which will be the same as a_count in this case).

It allows the caller (e.g., main function) to know how many elements are in the returned array.
*/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

struct Array
{
    int A[10];
    int size;
    int length;
};

void Display(int* a, int length)
{
    printf("\nElements are:\n");
    for (int i = 0; i < length; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int* reverseArray(int a_count, int* a, int* result_count) {
    int* reversed = (int *)malloc(a_count * sizeof(int));
    if (reversed == NULL) {
        *result_count = 0;
        return NULL;
    }

    for (int i = a_count - 1, j = 0; i >= 0; i--, j++) {
        reversed[j] = a[i];
    }

    *result_count = a_count;
    return reversed; 
}

int main()
{
    struct Array arr = {{2, 3, 10, 13, 17, 8}, 10, 6};

    int result_count;
    int* reversed = reverseArray(arr.length, arr.A, &result_count);

    if (reversed != NULL) {
        Display(reversed, result_count);
        free(reversed);  // Free dynamically allocated memory
    } else {
        printf("Memory allocation failed.\n");
    }

    return 0;
}



/*
Great question — let’s clear this up completely.

You're right to wonder: “Why do we pass result_count and why do we return a pointer to it?” It feels odd at first, but it's important because of how C handles return values and arrays.

🧠 Why result_count is Needed in C
❗ Problem with Returning Arrays in C:
In C, you can’t return an array directly (unlike Python or JavaScript). Instead, you return a pointer to a dynamically allocated array. But here’s the problem:

When you return a pointer to an array, the caller has no way to know how many elements are in it — unless you tell them.

📦 Solution: Use an Out Parameter (result_count)
We use result_count to tell the caller how many elements are in the returned array. It’s a technique called an out parameter.

Here’s how it works:

🔄 Analogy
You give the function an empty box (result_count), and say:

"Hey, after you’re done creating the reversed array, please write the array's length into this box so I know how many elements you gave me."

Then the function puts the length in the box like this:

c
Copy
Edit
*result_count = a_count;
*/
