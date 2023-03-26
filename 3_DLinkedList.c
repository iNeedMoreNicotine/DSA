# include <stdio.h>
# include <stdlib.h>
# include <time.h>

struct Node{
    int data;
    struct Node* prev;
    struct Node* next;
}; 

struct DLinkedLst{
    struct Node* head;
};

