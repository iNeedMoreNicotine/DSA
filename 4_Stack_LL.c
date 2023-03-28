# include <stdio.h>
# include <stdlib.h>
# include <time.h>

struct Node{
    int data;
    struct Node *next;
};

struct Node *top = NULL;

void push(int num){
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));

    // (*newNode).data = num;
    // (*newNode).next = top;
    newNode -> data = num;
    newNode -> next = top;

    top = newNode;
}

int pop(){
    if(top == NULL){
        printf("Stack underflow...\n");
        return -1;
    }
    else{
        struct Node *temp = top;
        int num = temp -> data;
        top = top -> next;
        free(temp);

        return num;
    }
}

void display(){
    if(top == NULL){
        printf("Empty stack!\n");
        return;
    }

    struct Node *cursor = top;
    printf("{");
    while(cursor -> next != NULL){
        printf("%d ", cursor -> data);
        cursor = cursor -> next;
    }
    printf("%d}\n", cursor -> data);
}

int randint(int min, int max){
    int x = rand() % (max - min + 1) + min;
    return x;
}




int main(){
    srand(time(NULL));

    for(int i = 0; i < 10; i++){
        push(randint(0, 69));
    }
    display();

    for(int j = 0; j < 5; j++){
        pop();
    }
    display();
    
    return 0;
}