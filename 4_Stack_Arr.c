# include <stdio.h>
# include <stdlib.h>
# include <time.h>
# define max_size 100

int stack[max_size];
int top = -1;

void push(int num){
    if(top == max_size - 1){
        printf("Stack overflow...\n");
        return;
    }
    top++;
    stack[top] = num;
    return;
}

int pop(){
    if(top == -1){
        printf("Stack underflow...\n");
        return -1;
    }
    int num = stack[top];
    top--;
    return num;
}

void display(){
    if(top == -1){
        printf("Empty stack!\n");
    }
    else{
        int temp = top;
        printf("{");
        while(temp != 0){
            printf("%d, ", stack[temp]);
            temp--;
        }
        printf("%d}\n", stack[temp]);
    }
}

int main(){
    int nums[] = {0, 5, 2, 6, 9, 25, 52, 69, 96, 5269};
    for(int i = 0; i < 10; i++){
        push(nums[i]);
    }
    display();

    for(int j = 0; j < 5; j++){
        pop();
    }
    display();

    return 0;
}