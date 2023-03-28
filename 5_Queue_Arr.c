# include <stdio.h>
# include <stdlib.h>
# include <time.h>
# define max_size 5

int queue[max_size];
int length = 0;
int start = 0;
int last = 0;

void enqueue(int num){
    if(length == max_size){
        printf("Queue is already full!\n");
        return;
    }

    queue[last] = num;
    if(last+1 > max_size-1){
        last = 0;
    }
    else{
        last++;
    }
    length++;
    return;
}

int dequeue(){
    if(length == 0){
        printf("Bruh, u can't dequeue if the queue is empty...\n");
        return -1;
    }
    int num = queue[start]; 
    if(start+1 > max_size-1){
        start = 0;
    }
    else{
        start++;
    }
    length--;
    return num;
}

void display(){
    if(length == 0){
        printf("Empty queue!\n");
    }

    int times = 0;
    int i = start;
    printf("<");
    while(times < length){
        if(times == length-1){
            printf("%d>\n", queue[i]);
        }
        else{
            printf("%d, ", queue[i]);
        }

        if(i+1 > max_size-1){
            i = 0;
        }
        else{
            i++;
        }
        times++;
    }
}

int main(){
    int nums[] = {0, 5, 2, 6, 9, 25, 52, 69, 96, 5269};
    
    printf("enqueue 5 numbers:\n");
    for(int i = 0; i < 5; i++){
        enqueue(nums[i]);
        }
    display();

    printf("dequeue 4 numbers:\n");
    int times = 0;
    while(times < 4){
        dequeue();
        times++;
    }
    display();

    printf("enque 3 numbers:\n");
    for(int j = 5; j < 8; j++){
        enqueue(nums[j]);
    }
    display();

    printf("deque 2 numbers:\n");
    for(int k = 8; k < 10; k++){
        dequeue();
    }
    display();

    printf("enque 1 number:\n");
    enqueue(96);
    display();

    return 0;
}