#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

struct Node{
    int data;
    struct Node *next;
}*first = NULL; // 'first' is a global pointer to the head of the list, initially NULL

void create(int A[], int n){
    int i;
    struct Node *t, *last; 
    // t is temporary pointer that will help in create new node.
    // 'last' will track the last node

    first=(struct Node *)malloc(sizeof(struct Node));
    first->data = A[0];
    first->next= NULL;
    last=first; // 'last' points to this first node for now.

    for (int i = 1; i < n; i++){ 
        t=(struct Node*)malloc(sizeof(struct Node)); // Allocate memory for new node
        t->data = A[i]; // Set its data from array
        t->next = NULL;  // Next is NULL since it will be added at the end
        last->next = t; // Link previous node to new node
        last = t;   // Move 'last' to new node
    }
}

void Display(struct Node *p){
    while (p != NULL){
        printf("%d ", p->data);
        p=p->next;
    }
}

void RDisplay(struct Node *p){
    if(p!=NULL){
        printf("%d ", p->data);
        RDisplay(p->next);
    }
}

int count(struct Node *p){
    int l = 0;
    while (p!=NULL)
    {
        l++;
        p=p->next;
    }
    return l;    
}

int Rcount(struct Node *p){
    if (p!=NULL){
        return Rcount(p->next)+1;
    }
    else{
        return 0;
    }
}

int sum(struct Node *p){
    int s = 0;
    while (p!=NULL)
    {
        s += p->data;
        p = p->next;
    }
    return s;    
}

int Rsum(struct Node *p){
    if (p==NULL){
        return 0;
    }
    else{
        return Rsum(p->next)+p->data;
    }
}

int Max(struct Node *p){
    int max = INT32_MIN;

    while (p!=NULL){
        if (p->data>max){
            max=p->data;
        }
        p=p->next;
    }
    return max;    
}

int RMax(struct Node *p){
    int x = 0;
    if (p==0){
        return INT32_MIN;
    }
    x=RMax(p->next);
    if(x>p->data){
        return x;
    }
    else return p->data;    
}

struct Node * LSearch(struct Node *p, int key){
    struct Node *q = NULL;

    while (p!=NULL){
        if (key==p->data){
            q->next = p->next;
            p->next = first;
            first = p;
            return p;
        }
        q=p;   
        p=p->next;
    }
    return NULL;    
}

struct Node * RSearch(struct Node *p, int key){
    if (p==NULL){
        return NULL;
    }
    if (key == p->data){
        return p;
    }
    return RSearch(p->next, key);    
}

int main() {
    int A[] = {3, 5, 7, 20, 15, 12};
    struct Node *temp;
    create(A, 6);
    // RDisplay(first);
    temp = LSearch(first, 12);
    temp = LSearch(first, 20);
    temp = LSearch(first, 7);
    if (temp){
        printf("Key is found %d\n", temp->data);
    }
    else
    {
        printf("Key is not found");
    }    
    Display(first);
    // printf("The length of the linked list is %d\n", Rcount(first));
    // printf("The length of the linked list is %d\n", Rsum(first));
    // printf("The maximum element in linked list is %d", RMax(first));
    return 0;
}