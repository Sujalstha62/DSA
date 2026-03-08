#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node *next;
};
struct node *front = NULL;
struct node *rear = NULL;
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
void enqueue() {
    int x;
    printf("Enter value to enqueue: ");
    if (scanf("%d", &x) != 1) {
        printf("Invalid input!\n");
        return;
    }    
    struct node* newn = createNode(x);
    if (rear == NULL) {
        front = rear = newn;
    } else {
        rear->next = newn;
        rear = newn;
    }
    printf("%d added to queue.\n", x);
}
int dequeue() {
    if (front == NULL) {
        printf("Queue Underflow! ");
        return INT_MIN;
    }    
    struct node* temp = front;
    int val = temp->data;
    front = front->next;
    if (front == NULL) {
        rear = NULL;
    }    
    free(temp);
    return val;
}
int peek() {
    if (front == NULL) {
        printf("Queue is empty! ");
        return INT_MIN;
    }
    return front->data;
}
void display() {
    if (front == NULL) {
        printf("Queue is empty!!\n");
        return;
    }
    struct node* t = front;
    printf("QUEUE (Front to Rear): ");
    while (t != NULL) {
        printf("%d -> ", t->data);
        t = t->next;
    }
    printf("NULL\n");
}
int main() {
    int choice, result;
    while (1) {
        printf("1) Enqueue\n2) Dequeue\n3) Peek\n4) Display\n5) Exit\nChoice: ");
        if (!scanf("%d", &choice)) break;
        switch (choice) {
            case 1:
                enqueue();
                break;
            case 2:
                result = dequeue();
                if (result != INT_MIN)
                    printf("Dequeued Value: %d\n", result);
                break;
            case 3:
                result = peek();
                if (result != INT_MIN)
                    printf("Front Value: %d\n", result);
                break;
            case 4:
                display();
                break;
            case 5:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
