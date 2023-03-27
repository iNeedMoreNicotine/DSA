# include <stdio.h>
# include <stdlib.h>
# include <time.h>

struct Node{
    int data;
    struct Node *prev;
    struct Node *next;
};

struct LinkedList{
    struct Node *head;
    struct Node *tail;
    int length;
    int is_empty;
};

void initList(struct LinkedList *list){
    (*list).head = NULL;
    (*list).tail = NULL;
    (*list).length = 0;
    (*list).is_empty = 1;
}

void insertAtStart(struct LinkedList *list, int num){
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));

    (*newNode).data = num;
    (*newNode).prev = NULL;
    (*newNode).next = (*list).head;

    if((*list).is_empty == 1){
        (*list).head = newNode;
        (*list).tail = newNode;
        (*list).is_empty = 0;
    }
    else{
        struct Node *temp = (*list).head;
        (*list).head = newNode;
        (*temp).prev = newNode;
    }
    (*list).length++;
}   

void insertAtEnd(struct LinkedList *list, int num){
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));

    (*newNode).data = num;
    (*newNode).prev = (*list).tail;
    (*newNode).next = NULL;

    if((*list).is_empty == 1){
        (*list).head = newNode;
        (*list).tail = newNode;
        (*list).is_empty = 0;
    }
    else{
        struct Node *temp = (*list).tail;
        (*list).tail = newNode;
        (*temp).next = newNode;
    }
    (*list).length++;
}

void insertAfterIndex(struct LinkedList *list, int num, int index){
    if(index == 0 || (*list).is_empty == 1){
        insertAtStart(list, num);
        return;
    }
    else if(index == (*list).length - 1){
        insertAtEnd(list, num);
        return;
    }

    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    struct Node *cursor = (*list).head;
    int current_index = 0;
    while(current_index != index){
        cursor = (*cursor).next;
        current_index++;
    }

    (*newNode).data = num;
    (*newNode).next = (*cursor).next;
    (*newNode).prev = cursor;

    (*cursor).next = newNode;
    (*(*newNode).next).prev = newNode;
    (*list).length++;
}

void deleteAtIndex(struct LinkedList *list, int index){
    if((*list).is_empty == 1){
        printf("Empty list!\n");
        return;
    }

    struct Node *cursor = (*list).head;
    int current_index = 0;
    while(current_index != index){
        cursor = (*cursor).next;
        current_index++;
    }
    (*(*cursor).prev).next = (*cursor).next;
    (*(*cursor).next).prev = (*cursor).prev;
    free(cursor);
    (*list).length -= 1;
}

void printList(struct LinkedList *list){
    if((*list).is_empty == 1){
        printf("Empty list!\n");
        return;
    }

    struct Node *cursor = (*list).head;
    printf("[");
    while((*cursor).next != NULL){
        printf("%d, ", (*cursor).data);
        cursor = (*cursor).next;
    }
    printf("%d]\n", (*cursor).data);
}

int randint(int min, int max){
    int x = rand() % (max - min + 1) + min;
    return x;
}




int main(){
    struct LinkedList list;
    initList(&list);

    srand(time(NULL));
    for(int i = 0; i < 5; i++){
        insertAtStart(&list, randint(0, 69));
    }
    for(int j = 0; j < 5; j++){
        insertAtEnd(&list, randint(0, 69));
    }
    printList(&list);
    for(int k = 0; k < 15; k++){
        insertAfterIndex(&list, randint(0, 69), 9);
        printList(&list);
    }
    for(int k = 0; k < 15; k++){
        deleteAtIndex(&list, 9);
        printList(&list);
    }

    printf("final length of the list: %d\n", list.length);

    return 0;
}