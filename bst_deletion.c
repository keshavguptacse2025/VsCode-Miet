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

struct BSTNode *min_value_node(struct BSTNode *node) {
    struct BSTNode *curr = node;
    while (curr && curr->left != NULL) {
        curr = curr->left;
    }
    return curr;
}

struct BSTNode *delete_node(struct BSTNode *root, int key) {
    if (root == NULL) return root;
    if (key < root->val) {
        root->left = delete_node(root->left, key);
    } else if (key > root->val) {
        root->right = delete_node(root->right, key);
    } else {
        if (root->left == NULL) {
            struct BSTNode *temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct BSTNode *temp = root->left;
            free(root);
            return temp;
        }
        struct BSTNode *temp = min_value_node(root->right);
        root->val = temp->val;
        root->right = delete_node(root->right, temp->val);
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
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    printf("Initial BST inorder: ");
    inorder(root);
    printf("\n");
    root = delete_node(root, 30);
    printf("After deleting 30: ");
    inorder(root);
    printf("\n");
    return 0;
}
