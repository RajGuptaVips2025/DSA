// Deleting the value from a given index.
// the code of C and C++ in this veru similiar that is why there is almost no seapartion of the code in that.

/* Binary Search
1. first the array should be sorted for binary search
2. we set low = index 0, high = length-1(or we can say last index), mid = [(low+high)/2] // for initial start
3. if the value we are finding is less than mid then we set new high equals to mid-1. //(h=mid-1)
4. if the value we are finding is more than mid then low will be set to mid+1. // (l=mid+1).
5. time complexity of binary search is O(log n) which is comparitvely better to linear search that has complexity of O(n).
5. best case is in binary search O(1), average case is O(log n) and worst case is O(log n).
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

void Display(struct Array arr)
{
    int i;
    printf("\n Elements are\n");
    for (int i = 0; i < arr.length; i++)
    {
        printf("%d ", arr.A[i]);
    }
}

int BinarySearch(struct Array *arr, int key){
    int l, mid, h;
    l=0;
    h= arr->length-1;

    while(l<=h){
        mid=(l+h)/2;
        if (key==arr->A[mid]){
            return mid;
        }
        else if (key<arr->A[mid]){
            h=mid-1;
        }
        else{
            l=mid+1;
        }   
    }
    return -1;
}



int main() {
    struct Array arr = {{2, 3, 4, 5, 6}, 10, 5};

    printf("%d\n", BinarySearch(&arr,5));
    cout<<"The index at the value"<<" 5 is "<<BinarySearch(&arr, 4)<<".";
    Display(arr);
    return 0;
}
