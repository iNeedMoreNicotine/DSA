# include <stdio.h>
# include <stdlib.h>
# include <time.h>
# define max_size 10

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

int randint(int min, int max){
    int x = rand() % (max - min + 1) + min;
    return x;
}

void enqueue_randint(int n){
    printf("enqueue %d nums:\n", n);
    int times = 0;
    while(times < n){
        enqueue(randint(0, 69));
        times++;
    }
    display();
}

void dequeue_randint(int n){
    printf("dequeue %d nums:\n", n);
    int times = 0;
    while(times < n){
        dequeue();
        times++;
    }
    display();
}




int main(){
    for(int i = 10; i > 0; i--){
        enqueue_randint(i);
        dequeue_randint(i-1);
    }
    
    return 0;
}