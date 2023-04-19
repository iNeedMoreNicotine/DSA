# include <stdio.h>
# include <stdlib.h>
# include <time.h>
# define length 15


int randint(int min, int max){
    int x = rand() % (max - min + 1) + min;
    return x;
}

int getMinIndex(int arr[], int l, int r){
    int minIndex = l;
    for(int i = l+1; i < r; i++){
        if(arr[i] < arr[minIndex]){
            minIndex = i;
        }
    }
    return minIndex;
}

int selectionSort(int arr[], int len){
    for(int i = 0; i < len; i++){
        int minIndex = getMinIndex(arr, i, len);
        // swap()
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}

void insert(int A[], int index){
    int tmp = A[index];
    int i = index-1;

    while(i > -1 && A[i] > tmp){
        A[i+1] = A[i];
        i -= 1;
    }
    A[i+1] = tmp;
}

void insertionSort(int A[], int len){
    for(int i = 0; i < len; i++){
        insert(A, i);
    }
}

void initArr(int arr[], int len){
    srand(69);
    for(int i = 0; i < len; i++){
        arr[i] = randint(0, 69);
    }
}

void printArr(int arr[], int len){
    printf("[");
    for(int i = 0; i < len; i++){
        if(i != len - 1){
            printf("%d,", arr[i]);
        }
        else{
            printf("%d", arr[i]);
        }
    }
    printf("]\n");
}




int main(){
    int arr[length];

    // init random array
    printf("Origin unsorted array:\n");
    initArr(arr, length);
    printArr(arr, length);
    printf("\n");

    // selection sort
    printf("Selection sort:\n");
    selectionSort(arr, length);
    printArr(arr, length);
    printf("\n");

    // insertion sort
    initArr(arr, length);
    printf("Insertion sort:\n");
    insertionSort(arr, length);
    printArr(arr, length);
    printf("\n");

    // heap sort
    // tree sort
    // bubble sort
    // quick sort
    // merge sort
}