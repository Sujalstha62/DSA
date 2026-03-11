#include <stdio.h>
#include <stdlib.h>
// 1. Node Structure
typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;
// Global root for the BST session
Node *root = NULL;
Node* createNode(int value) {
    Node* newn = (Node*)malloc(sizeof(Node));
    if (newn == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newn->data = value;
    newn->left = NULL;
    newn->right = NULL;
    return newn;
}
// 2. Recursive BST Insertion Logic
// This replaces the Queue-based insertion
Node* insertBST(Node* node, int value) {
    // If the spot is empty, create the node here
    if (node == NULL) return createNode(value);
    // Traverse left if value is smaller, right if larger
    if (value<node->data) node->left=insertBST(node->left, value);
	else if (value > node->data) node->right=insertBST(node->right, value);
    return node;
}
// 3. Traversal Functions
void displayIn(Node *t) {
    if (t == NULL) return;
    displayIn(t->left);
    printf("%d\t", t->data);
    displayIn(t->right);
}
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
void freeTree(Node* t) {
    if (t == NULL) return;
    freeTree(t->left);
    freeTree(t->right);
    free(t);
}
void searchWithPath(Node* root, int target) {
    if (root == NULL) {
        printf("Tree is empty. Value not found.\n");
        return;
    }
    Node* temp = root;
    printf("Search Path: ");
    while (temp != NULL) {
        printf("%d", temp->data);
        if (temp->data == target) {
            printf("\nResult: Value %d found in the tree!\n", target);
            return;
        }
        printf(" -> "); // Visual separator for the path
        if (target < temp->data) temp = temp->left;
        else temp = temp->right;
    }
    printf("NULL\nResult: Value %d not found in the tree.\n", target);
}
int main() {
    Node* root = NULL;
    int x, choice, target,dis;
    char session;
    do {
        root = NULL;
        printf("Enter integers for BST (non-numeric to stop): ");
        while (scanf("%d", &x)) root = insertBST(root, x);
        while(getchar() != '\n'); 
        while (1) {
            printf("\n1) Display\n2) Search for Value\n3) Exit Session\nChoice: ");
            scanf("%d", &choice);
            if (choice == 1) {
            	printf("1)Inorder\n2)Postorder\n3)Preorder\nChoice(Any character to exit):");
            	while(scanf("%d",&dis)){
            		if(dis==1)displayIn(root);
            		else if(dis==2)displayPost(root);
            		else if(dis==3)displayPre(root);
            		else break;
            		printf("\n1)Inorder\n2)Postorder\n3)Preorder\nChoice:");
				}
				while(getchar() != '\n'); 
            } else if (choice == 2) {
                printf("Enter value to search: ");
                scanf("%d", &target);
                searchWithPath(root, target);
            } else break;
        }
        printf("\nNew tree session? (Y/N): ");
        scanf(" %c", &session);
        freeTree(root); 
    } while (session == 'y' || session == 'Y');
    return 0;
}
