#include <stdio.h>
#include <stdlib.h>

struct BSTNode {
    int val;
    struct BSTNode *left;
    struct BSTNode *right;
};

struct BSTNode *create_node(int val) {
    struct BSTNode *node = (struct BSTNode *)malloc(sizeof(struct BSTNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

struct BSTNode *insert(struct BSTNode *root, int val) {
    if (root == NULL) return create_node(val);
    if (val < root->val) {
        root->left = insert(root->left, val);
    } else if (val > root->val) {
        root->right = insert(root->right, val);
    }
    return root;
}

void inorder(struct BSTNode *root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->val);
    inorder(root->right);
}

int main() {
    struct BSTNode *root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
    printf("Inorder traversal of BST: ");
    inorder(root);
    printf("\n");
    return 0;
}
