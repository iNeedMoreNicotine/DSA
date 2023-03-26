# include <stdio.h>
# include <stdlib.h>
# include <time.h> 
# define MAX_SIZE 6969

int arr[MAX_SIZE];
int lenOfArr = 0;

int getMinIndex(int A[], int l, int r){
    int min_index = l;
    for(int i = l+1; i < r; i++){
        if(A[i] < A[min_index]){
            min_index = i;
        }
    }
    return min_index;
}

void selectionSort(int A[], int len){
    for(int i = 0; i < len; i++){
        int min_index = getMinIndex(A, i, len);
        int tmp = A[i];
        A[i] = A[min_index];
        A[min_index] = tmp;
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

void removeByIndex(int A[], int index, int len){
    int i = index + 1;
    while(i < len){
        A[i-1] = A[i];
        i++;
    }
    lenOfArr -= 1;
}

// put num into ordered array 
void addElement(int A[], int num){
    if(lenOfArr == 0){
        A[0] = num;
        lenOfArr++;
        return;
    } else{
        int i = lenOfArr-1;
        while(i > -1 && A[i] > num){
            A[i+1] = A[i];
            i -= 1;
        }
        A[i+1] = num;
        lenOfArr++;
    }
}

// search algos
int seqSearch_improved(int key, int A[], int len){
    for(int i = 0; i < len; i++){
        if(A[i] == key){
            return i;
        } else if(A[i] > key){
            return -1;
        }
    }
}

int binSearch(int key, int A[], int len){
    int l = 0;
    int r = len;

    while(l <= r){
        int mid = (l+r)/2;
        if(A[mid] == key){
            return mid;
        } else if(A[mid] > key){
            r = mid-1;
        } else{
            l = mid+1;
        }
    }
    return -1;
}

int randint(int min, int max){
    int x = rand() % (max - min + 1) + min;
    return x;
}

void printArr(int A[], int len){
    for(int i = 0; i < len; i++){
        if(i == 0){
            printf("[%d,", A[i]);
        } else if(i == len-1){
            printf("%d]\n", A[i]);
        } else{
            printf("%d,", A[i]);
        }
    }
}




int main(){
    int tmp[12] = {5, 2, 6, 9, 52, 69, 5269, 6952, 25, 96, 9625, 2596};
    for(int i = 0; i < 12; i++){
        addElement(arr, tmp[i]);
    }

    // srand(time(NULL));
    // for(int i = 0; i < 25; i++){
    //     addElement(arr, randint(0, 69));
    // }

    printf("original array:\n");
    printArr(arr, lenOfArr);
    printf("length of the arr: %d\n", lenOfArr);
    printf("\n");

    // // selection sort
    // selectionSort(arr, lenOfArr);
    // printArr(arr, lenOfArr);

    // insertion sort
    // insertionSort(arr, lenOfArr);
    // printArr(arr, lenOfArr);

    // removeByIndex(arr, 0, lenOfArr);
    // printArr(arr, lenOfArr);

    // // seq search
    // printf("search for 69:\n");
    // int index = seqSearch_improved(69, arr, lenOfArr);
    // if(index == -1){
    //     printf("69 does not exist!\n");
    // } else{
    //     printf("69 founded! location = %d\n", index);
    // }

    // binary search
    printf("search for 5269:\n");
    int index = binSearch(5269, arr, lenOfArr);
    if(index == -1){
        printf("5269 does not exist!\n");
    } else{
        printf("5269 founded! location in arr = %d\n", index);
    }

    printf("\n");
}