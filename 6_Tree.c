# include <stdio.h>
# include <stdlib.h>
# include <time.h>

struct Node{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node* createNode(int num){
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    
    newNode -> data = num;
    newNode -> left = NULL;
    newNode -> right = NULL;
    
    return newNode;
}

// binary search tree
struct Node* insertNode(struct Node *root, int num){
    if(root == NULL){
        root = createNode(num);
    }
    else if(num <= root -> data){
        // insert to left subtree
        root -> left = insertNode(root -> left, num);
    }
    else{
        // insert to right subtree
        root -> right = insertNode(root -> right, num);
    }
}

void inOrderTraversal(struct Node *root){
    if(root != NULL){
        inOrderTraversal(root -> left);
        printf("%d ", root -> data);
        inOrderTraversal(root -> right);
    }
    return;
}

int randint(int min, int max){
    int x = rand() % (max - min + 1) + min;
    return x;
}




int main(){
    srand(time(NULL));
    struct Node *root = NULL;
    int arr[20];
    for(int i = 0; i < 20; i++){
        arr[i] = randint(0, 69);
    }
    printf("Origin Array:\n");
    for(int i = 0; i < 20; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
    for(int i = 0; i < 20; i++){
        root = insertNode(root, arr[i]);
    }

    printf("In Order Traversal of Bin Search Tree:\n");
    inOrderTraversal(root);
    printf("\n");
    
    return 0;
}