#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;

    struct Node *left, *right;
} Node;

Node* buildTree(int *tree, int *idx) {
    (*idx)++;

    if (tree[*idx] == -1)
        return NULL;

    Node* root = (Node*)malloc(sizeof(Node));

    root->data = tree[*idx];

    root->left = buildTree(tree, idx);
    root->right = buildTree(tree, idx);

    return root;
}

void print(Node *root) {
    if (root == NULL) {
        printf("-1 ");
        return;
    }

    printf("%d ", root->data);
}

void preorder(Node* root) {
    if (root == NULL)
        return;

    print(root);
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node* root) {
    if (root == NULL)
        return;

    inorder(root->left);
    print(root);
    inorder(root->right);
}

void postorder(Node* root) {
    if (root == NULL)
        return;

    postorder(root->left);
    postorder(root->right);
    print(root);
}

int main() {
    int tree[] = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    int idx = -1;

    Node *root = buildTree(tree, &idx);

    printf("Preorder: ");
    preorder(root);

    printf("\nInorder: ");
    inorder(root);

    printf("\nPostorder: ");
    postorder(root);
}