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

struct BSTNode *search(struct BSTNode *root, int key) {
    if (root == NULL || root->val == key) return root;
    if (key < root->val) return search(root->left, key);
    return search(root->right, key);
}

int main() {
    struct BSTNode *root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    int target = 40;
    struct BSTNode *found = search(root, target);
    if (found != NULL) {
        printf("Key %d found in BST\n", target);
    } else {
        printf("Key %d not found\n", target);
    }
    return 0;
}
