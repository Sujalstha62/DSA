#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node *t;
struct node* createNode(int val) {
    struct node* newn = (struct node*)malloc(sizeof(struct node));
    if (newn == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newn->data = val;
    newn->next = NULL;
    return newn;
}
void addlast(int x, struct node** head_ref) {
    struct node* newn = createNode(x);
    if (*head_ref == NULL) {
        *head_ref = newn;
        return;
    }
    t = *head_ref;
    while (t->next != NULL) t=t->next;
    t->next = newn;
}
void display(struct node* head) {
    t = head;
    while (t != NULL) {
        printf("%d -> ", t->data);
        t = t->next;
    }
    printf("NULL");
}
int main() {
	int i;
    int n, hash_val, hash_key;   
    printf("Enter the number of available locations (hash table size): ");
    scanf("%d",&n);
    struct node** arr = (struct node**)malloc(n * sizeof(struct node*));
    for (i=0;i<n;i++) arr[i] = NULL;
    printf("Enter numbers:\n");
    while (scanf("%d", &hash_val)) {
        hash_key = hash_val % n;
        if (hash_key < 0) hash_key += n; 
        addlast(hash_val, &arr[hash_key]);
    }
    printf("\n--- Hash Table Contents ---\n");
    for (i=0;i<n;i++){
        printf("Index [%d]: ", i);
        display(arr[i]);
        printf("\n");
    }
    for (i=0;i<n;i++){
        struct node* curr = arr[i];
        while (curr != NULL) {
            struct node* temp = curr;
            curr = curr->next;
            free(temp);
        }
    }
    free(arr);
    return 0;
}
