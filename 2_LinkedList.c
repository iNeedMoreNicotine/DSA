#include <stdio.h>
#include <stdlib.h>
# include <time.h> 

// Define the Node struct
struct Node{
    int data;
    struct Node* next;
};

// def llist
struct LinkedList{
    struct Node* head;
};

void initList(struct LinkedList* list){
    list -> head = NULL;
}

void insertAtStart(struct LinkedList* list, int num){
    // alloc memory for new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    
    // init new node 
    newNode -> data = num;
    newNode -> next = list -> head;

    // reset the head of the list
    list -> head = newNode;
}

void insertAtEnd(struct LinkedList* list, int num){
    // alloc memory for new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    // init new node
    newNode -> data = num;
    newNode -> next = NULL;

    // if lst is empty, set the head to the new node
    if(list -> head == NULL){
        list -> head = newNode;
    }
    // else, insert at the end
    else{
        struct Node* cursor = list -> head;
        while(cursor -> next != NULL){
            cursor = cursor -> next;
        }
        cursor -> next = newNode;
    }
}

void deleteFirstNode(struct LinkedList* list){
    // If the list is empty, return
    if (list -> head == NULL) {
        return;
    }

    struct Node* temp = list -> head;
    list -> head = list -> head -> next;

    // free to prev memory leak
    free(temp);
}

void printList(struct LinkedList* list){
    if(list -> head == NULL){
        printf("Empty list!");
        return;
    }

    struct Node* cursor = list -> head;
    printf("[");
    while(cursor -> next != NULL){
        printf("%d, ", cursor -> data);
        cursor = cursor -> next;
    }
    printf("%d", cursor -> data);
    printf("]\n");
}

int randint(int min, int max){
    int x = rand() % (max - min + 1) + min;
    return x;
}




int main(){
    struct LinkedList list;
    initList(&list);

    // Add nodes to the list
    srand(time(NULL));
    // insert at start
    for(int i = 0; i < 10; i++){
        insertAtStart(&list, randint(0, 69));
    }
    // insert at end
    for(int j = 0; j < 10; j++){
        insertAtEnd(&list, randint(0, 69));
    }

    // Print the list
    printList(&list);

    // Delete the first node
    deleteFirstNode(&list);

    // Print the list again
    printList(&list);

    return 0;
}