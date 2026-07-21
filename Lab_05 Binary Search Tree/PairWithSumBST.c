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
    if(root == NULL)
        return createNode(data);

    if(data < root->data)
        root->left = insert(root->left, data);
    else
        root->right = insert(root->right, data);

    return root;
}

void inorder(struct Node* root, int arr[], int *index) {
    if(root != NULL)
    {
        inorder(root->left, arr, index);
        arr[(*index)++] = root->data;
        inorder(root->right, arr, index);
    }
}

int main() {
    
    struct Node *root = NULL;
    int n, i, value, target;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter node values:\n");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &value);
        root = insert(root, value);
    }

    printf("Enter target: ");
    scanf("%d", &target);

    int arr[100];
    int index = 0;

    inorder(root, arr, &index);

    int left = 0;
    int right = index - 1;

    while(left < right)
    {
        int sum = arr[left] + arr[right];

        if(sum == target)
        {
            printf("True");
            return 0;
        }
        else if(sum < target)
            left++;
        else
            right--;
    }

    printf("False");

    return 0;
}