# include <stdio.h>
# include <stdlib.h>

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

struct Node* insertNode(struct Node *root, int num){
    if(root == NULL){
        root = createNode(num);
    }
    else if(num <= root -> data){
        root -> left = insertNode(root -> left, num);
    }
    else{
        root -> right = insertNode(root -> right, num);
    }

    return root;
}

void inOrderTraversal(struct Node *root){
    if(root != NULL){
        inOrderTraversal(root -> left);
        printf("%d ", root -> data);
        inOrderTraversal(root -> right);
    }
    
    return;
}

int main(){
    struct Node *root = NULL;
    int nums[] = {5, 3, 7, 1, 4, 6, 8, 2};
    for(int i = 0; i < 8; i++){
        root = insertNode(root, nums[i]);
    }

    printf("In-Order Traversal of Tree: ");
    inOrderTraversal(root);
    printf("\n");

    return 0;
}