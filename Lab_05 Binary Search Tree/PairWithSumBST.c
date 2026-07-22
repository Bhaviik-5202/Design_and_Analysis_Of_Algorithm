#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* root, int data) {
    if(root == NULL) {
        return createNode(data);
    }

    if(data < root->data) {
        root->left = insert(root->left, data);
    }
    else {
        root->right = insert(root->right, data);
    }

    return root;
}

struct Node* search(struct Node* root, int key) {
    if(root == NULL || root->data == key) {
        return root;
    }

    if(key < root->data) {
        return search(root->left, key);
    }

    return search(root->right, key);
}

int findPair(struct Node* root, struct Node* current, int target) {
    if(current == NULL) {
        return 0;
    }

    int complement = target - current->data;

    struct Node* temp = search(root, complement);

    if(temp != NULL && temp != current)
        return 1;

    if(findPair(root, current->left, target))
        return 1;

    return findPair(root, current->right, target);
}

int main() {

    struct Node* root = NULL;
    int n, value, target;

    printf("Enter number of nodes: ");
    scanf("%d",&n);

    printf("Enter node values:\n");

    for(int i=0;i<n;i++) {
        scanf("%d",&value);
        root = insert(root,value);
    }

    printf("Enter target: ");
    scanf("%d",&target);

    if(findPair(root, root, target))
        printf("True");
    else
        printf("False");

    return 0;
}