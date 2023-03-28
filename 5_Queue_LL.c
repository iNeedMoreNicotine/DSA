# include <stdio.h>
# include <stdlib.h>
# include <time.h>

struct Node{
    int data;
    struct Node *next;
};

struct Queue{
    int length;
    struct Node *first;
    struct Node *last;
};

void initQueue(struct Queue *queue){
    queue -> length = 0;
    queue -> first = NULL;
    queue -> last = NULL;
}

void enqueue(struct Queue *queue, int num){
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode -> data = num;
    newNode -> next = NULL;

    if(queue -> length == 0){
        queue -> first = newNode;
        queue -> last = newNode;
        queue -> length++;
        return;
    }
    else{
        queue -> last -> next = newNode;
        queue -> last = newNode;
        queue -> length++;
    }
}

int dequeue(struct Queue *queue){
    struct Node *temp = queue -> first;

    if(queue -> length == 0){
        printf("Empty queue...\n");
        return -1;
    }
    else{
        int num = queue -> first -> data;
        queue -> first = queue -> first -> next;
        queue -> length--;
        free(temp);
        return num;
    }
}

void display(struct Queue *queue){
    if(queue -> length == 0){
        printf("Empty queue...\n");
        return;
    }
    struct Node *cursor = queue -> first;
    printf("<");
    while(cursor -> next != NULL){
        printf("%d, ", cursor -> data);
        cursor = cursor -> next;
    }
    printf("%d>\n", cursor -> data);
}




int main(){
    struct Queue queue;
    initQueue(&queue);

    int nums[] = {0, 5, 2, 6, 9, 25, 52, 69, 96, 5269};
    for(int i = 0; i < 10; i++){
        enqueue(&queue, nums[i]);
    }
    printf("length of queue: %d\n", queue.length);
    display(&queue);

    for(int j = 0; j < 5; j++){
        dequeue(&queue);
    }
    printf("length of queue: %d\n", queue.length);
    display(&queue);
    

    return 0;
}