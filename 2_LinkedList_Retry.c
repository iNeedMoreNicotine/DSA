# include <stdio.h>
# include <stdlib.h>
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

void initList(struct LinkedList *list){
    (*list).head = NULL;
}

void insertAtStart(struct LinkedList *list, int num){
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));

    // init new node
    (*newNode).data = num;
    (*newNode).next = (*list).head;

    // reset the head of list
    (*list).head = newNode;
}

void insertAtEnd(struct LinkedList *list, int num){
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));

    // init new node
    (*newNode).data = num;
    (*newNode).next = NULL;

    // if the lst is empty..
    if((*list).head == NULL){
        (*list).head = newNode;
    }
    else{
        // else, insert at the end
        struct Node *cursor = (*list).head;
        while((*cursor).next != NULL){
            cursor = (*cursor).next;
        }
        (*cursor).next = newNode;
    }
}

void deleteFirstNode(struct LinkedList *list){
    // if the list is empty, return
    if((*list).head == NULL){
        return;
    }

    struct Node *temp = (*list).head;
    (*list).head = (*(*list).head).next;

    free(temp);
}

void printList(struct LinkedList *list){
    if((*list).head == NULL){
        printf("Empty list!");
        return;
    }
    else{
        struct Node *cursor = (*list).head;
        printf("[");
        while((*cursor).next != NULL){
            printf("%d ", (*cursor).data);
            cursor = (*cursor).next;
        }
        printf("%d]\n", (*cursor).data);
    }
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