#include <stdio.h>
#include <stdlib.h>
#define N 20
// 1. Tree Node Structure (Changed to int)
typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;
Node *start = NULL;
Node* createNode(int value) {
    Node* newn = (Node*)malloc(sizeof(Node));
    newn->data = value;
    newn->left = NULL;
    newn->right = NULL;
    return newn;
}
// 2. Circular Queue Structure
typedef struct {
    int top, bottom;
    Node* arr[N];
} CirQueue;
void initQueue(CirQueue* q) {
    q->top = q->bottom = -1;
}
void enqueue(CirQueue* q, Node* n) {
    if (q->top == N - 1 && q->bottom == -1) return;
    q->top++;
    q->arr[q->top % N] = n;
}
Node* dequeue(CirQueue* q) {
    if (q->top == q->bottom) return NULL;
    q->bottom++;
    return q->arr[q->bottom % N];
}
Node* peek(CirQueue* q) {
    if (q->top == q->bottom) return NULL;
    return q->arr[(q->bottom + 1) % N];
}
// 3. Heap Tree Logic
typedef struct {
    CirQueue A;
    int count;
    Node *root;
} HeapTree;
void initHeap(HeapTree* ht) {
    initQueue(&(ht->A));
    ht->count = 0;
    ht->root = NULL;
    start = NULL;
}
void insert(HeapTree* ht, int value) {
    if (ht->root == NULL) {
        ht->root = createNode(value);
        start = ht->root;
        enqueue(&(ht->A), ht->root);
        ht->count = 1;
    } else {
        Node *parent;
        // Logic to maintain complete binary tree property
        if (ht->count % 2 != 0) parent = peek(&(ht->A));
        else parent = dequeue(&(ht->A));
        Node* newNode = createNode(value);
        if (parent->left == NULL) parent->left=newNode;
        else parent->right = newNode;
        enqueue(&(ht->A), newNode);
        ht->count++;
    }
}
// 4. Traversal Functions
void displayPre(Node *t) {
    if (t == NULL) return;
    printf("%d\t", t->data);
    displayPre(t->left);
    displayPre(t->right);
}
void displayPost(Node *t) {
    if (t == NULL) return;
    displayPost(t->left);
    displayPost(t->right);
    printf("%d\t", t->data);
}
void displayIn(Node *t) {
    if (t == NULL) return;
    displayIn(t->left);
    printf("%d\t", t->data);
    displayIn(t->right);
}
void freeTree(Node* t) {
    if (t == NULL) return;
    freeTree(t->left);
    freeTree(t->right);
    free(t);
}
int main() {
    HeapTree ht;
    char ch, order;
    int x;
    do {
        initHeap(&ht);
        printf("Enter integers (enter any non-numeric character to stop): ");
        while (scanf("%d", &x)) insert(&ht, x);
        // Clear the buffer after non-numeric input stops the loop
        while(getchar() != '\n'); 
        while (1) {
            printf("\n1) Inorder\n2) Postorder\n3) Preorder\n4) Back\nChoice: ");
            scanf(" %c", &order);
            if (order == '1') { printf("Inorder: "); displayIn(start); printf("\n"); }
            else if (order == '2') { printf("Postorder: "); displayPost(start); printf("\n"); }
            else if (order == '3') { printf("Preorder: "); displayPre(start); printf("\n"); }
            else break;
        }
        printf("\nEnter 'Y' for new session: ");
        scanf(" %c", &ch);
        freeTree(start);
    } while (ch == 'y' || ch == 'Y');
    return 0;
}
