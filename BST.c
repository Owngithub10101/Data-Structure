#include <stdio.h>
#include <stdlib.h>
struct node{
        int data;
        struct node* left;
        struct node* right;
};


struct node* newNode(int data){
        struct node* temp = (struct node*)malloc(sizeof(struct node));
        temp->data = data;
        temp->left = temp->right = NULL;
        return temp;
}

struct node* insert(struct node* node, int data){
        if(node == NULL)
                return newNode(data);
        if(data < node->data){
                node->left = insert(node->left, data);
        }
        else if(data > node->data){
                node->right = insert(node->right, data);
        }
        return node;
        
}

void preorder(struct node* root){
        if(root == NULL)
                return ;
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
}

void inorder(struct node* root){
        if(root == NULL)
                return ;
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
}

void postorder(struct node* root){
        if(root == NULL)
                return ;
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
}

int main(){
        int i;
        int arr[5];
        printf("Enter the elements : ");
        for(i = 0; i < 5; ++i){
                scanf("%d", &arr[i]);
        }
        struct node* root = NULL;
        root = insert(root, arr[0]);
        for(i = 1; i < 5; ++i){
                insert(root, arr[i]);
        }
        printf("Our preorder traversal is : \n");
        preorder(root);
        printf("\nOur inorder traversal is : \n");
        inorder(root);
        printf("\nOur postorder traversal is : \n");
        postorder(root);
        
    return 0;
}
