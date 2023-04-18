# include <stdio.h>
# include <stdlib.h>
# include <time.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

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

// ensures that each subtree rooted at index i is heapified properly
void buildMaxHeap(int arr[], int n){
    for (int i = n/2 - 1; i >= 0; i--){
        maxHeapify(arr, n, i);
    }
    // or
    // maxHeapify(arr, n, 0);
}

void insertMaxHeap(int arr[], int *n, int key){
    (*n)++;
    int i = *n - 1;
    arr[i] = key;

    // from bottom to top
    while(i > 0 && arr[(i-1) / 2] < arr[i]){
        swap(&arr[i], &arr[(i-1) / 2]);
        i = (i-1) / 2;
    }
}

int removeMaxHeap(int arr[], int *n){
    if(*n <= 0){
        return -1;
    }

    int max = arr[0];
    arr[0] = arr[*n - 1];
    (*n)--;
    maxHeapify(arr, *n, 0);

    return max;
}

void heapSort(int arr[], int n){
    buildMaxHeap(arr, n);

    for(int i = n-1; i >= 1; i--){
        swap(&arr[0], &arr[i]);
        maxHeapify(arr, i, 0);
    }
}




int main() {
    int arr[] = {52, 69, 37, 22, 31};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original Array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    buildMaxHeap(arr, n);

    printf("\nMax Heap: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    insertMaxHeap(arr, &n, 34);
    printf("\nMax Heap after inserting 34: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    int max = removeMaxHeap(arr, &n);
    printf("\nMax Element removed from Max Heap: %d", max);

    printf("\nMax Heap after removing max element: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    heapSort(arr, n);

    printf("\nSorted Array using Heap Sort: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}