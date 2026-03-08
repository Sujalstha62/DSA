#include <stdio.h>
#include <stdlib.h>

// 1. Updated Node Structure with Height
typedef struct Node {
    int data;
    int height;
    struct Node *left;
    struct Node *right;
} Node;

// Helper to get max of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Helper to get height of a node
int getHeight(Node *n) {
    if (n == NULL) return 0;
    return n->height;
}

// Helper to get Balance Factor
int getBalance(Node *n) {
    if (n == NULL) return 0;
    return getHeight(n->left) - getHeight(n->right);
}

Node* createNode(int value) {
    Node* newn = (Node*)malloc(sizeof(Node));
    newn->data = value;
    newn->left = newn->right = NULL;
    newn->height = 1; // New nodes are added at height 1
    return newn;
}

// 2. Rotation Functions


// Right Rotate (fixes Left-Left imbalance)
Node* rightRotate(Node *y) {
    Node *x = y->left;
    Node *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

    return x;
}

// Left Rotate (fixes Right-Right imbalance)
Node* leftRotate(Node *x) {
    Node *y = x->right;
    Node *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

    return y;
}

// 3. AVL Insertion Logic
Node* insertAVL(Node* node, int value) {
    // Standard BST Insertion
    if (node == NULL) return createNode(value);

    if (value < node->data)
        node->left = insertAVL(node->left, value);
    else if (value > node->data)
        node->right = insertAVL(node->right, value);
    else
        return node; // No duplicates

    // Update Height
    node->height = 1 + max(getHeight(node->left), getHeight(node->right));

    // Get Balance Factor
    int balance = getBalance(node);

    // LL Case
    if (balance > 1 && value < node->left->data)
        return rightRotate(node);

    // RR Case
    if (balance < -1 && value > node->right->data)
        return leftRotate(node);

    // LR Case
    if (balance > 1 && value > node->left->data) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // RL Case
    if (balance < -1 && value < node->right->data) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

// Traversal (Inorder)
void displayIn(Node *root) {
    if (root != NULL) {
        displayIn(root->left);
        printf("%d (H:%d)\n", root->data, root->height);
        displayIn(root->right);
    }
}

int main() {
    Node* root = NULL;
    int x;
    printf("Enter integers for AVL tree (non-numeric to stop): ");
    while (scanf("%d", &x) == 1) {
        root = insertAVL(root, x);
    }

    printf("\nAVL Tree (Inorder with Heights): ");
    displayIn(root);
    printf("\n");

    return 0;
}
