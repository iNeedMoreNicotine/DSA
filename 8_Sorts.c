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

void insert(int arr[], int index){
    int temp = arr[index];
    int i = index - 1;

    while(i > -1 && arr[i] > temp){
        arr[i+1] = arr[i];
        i -= 1;
    }
    arr[i+1] = temp;
}

void insertionSort(int arr[], int len){
    for(int i = 0; i < len; i++){
        insert(arr, i);
    }
}

// Heap
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

// implement heap data structute in an array...
// n: length of array
// i: index of current heap node
void maxHeapify(int arr[], int n, int i){
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left < n && arr[left] > arr[largest]){
        largest = left;
    }
    if (right < n && arr[right] > arr[largest]){
        largest = right;
    }

    if (largest != i){
        swap(&arr[i], &arr[largest]);
        maxHeapify(arr, n, largest);
    }
}

void buildMaxHeap(int arr[], int n){
    for (int i = n/2 - 1; i >= 0; i--){
        maxHeapify(arr, n, i);
    }
}

void heapSort(int arr[], int n){
    buildMaxHeap(arr, n);

    for(int i = n-1; i >= 1; i--){
        swap(&arr[0], &arr[i]);
        maxHeapify(arr, i, 0);
    }
}

void bubbleSort(int arr[], int len){
    for(int i = 0; i < len; i++){
        for(int j = 0; j < len - 1; j++){
            if(arr[j] > arr[j+1]){
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}

void initArr(int arr[], int len){
    srand(526969);
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
    initArr(arr, length);
    printf("Heap sort:\n");
    heapSort(arr, length);
    printArr(arr, length);
    printf("\n");
    
    // bubble sort
    initArr(arr, length);
    printf("Bubble sort:\n");
    bubbleSort(arr, length);
    printArr(arr, length);
    printf("\n");

    // quick sort
    
    // merge sort
}