#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    char val;
    struct Node *left;
    struct Node *right;
} Node;

Node* new_node(char val) {
    Node* n = malloc(sizeof(Node));
    n->val = val;
    n->left = n->right = NULL;
    return n;
}

Node* build_tree(char arr[], int n, int i) {
    if (i >= n) return NULL;
    Node* root = new_node(arr[i]);
    root->left = build_tree(arr, n, 2 * i + 1);
    root->right = build_tree(arr, n, 2 * i + 2);
    return root;
}

void print_spaces(int count) {
    for (int i = 0; i < count; i++) printf(" ");
}

void print_level(Node* root, int level, int depth) {
    if (!root) return;
    if (level == 1) {
        print_spaces(depth * 3);
        printf("%c ", root->val);
    } else if (level > 1) {
        print_level(root->left, level - 1, depth);
        print_level(root->right, level - 1, depth);
    }
}

int height(Node* root) {
    if (!root) return 0;
    int lh = height(root->left);
    int rh = height(root->right);
    return (lh > rh ? lh : rh) + 1;
}

void print_tree_vertical(Node* root) {
    int h = height(root);
    for (int i = 1; i <= h; i++) {
        print_level(root, i, h - i);
        printf("\n");
    }
}

void free_tree(Node* root) {
    if (!root) return;
    free_tree(root->left);
    free_tree(root->right);
    free(root);
}

int main() {
    char arr[] = { 'G', 'D', 'I', 'B', 'F', 'H', 'J', 'A', 'C', 'E' };
    int n = sizeof(arr) / sizeof(arr[0]);
    Node* root = build_tree(arr, n, 0);
    printf("Complete binary tree:\n\n");
    print_tree_vertical(root);
    free_tree(root);
    printf("Full binary tree:\n\n");


    return 0;
}
