#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node *next;
};
struct node *top = NULL;
struct node* createNode(int val) {
    struct node* newn = (struct node*)malloc(sizeof(struct node));
    if (newn == NULL) {
        printf("Stack Overflow!\n");
        exit(1);
    }
    newn->data = val;
    newn->next = NULL;
    return newn;
}
void push(int x) {
    struct node* newn = createNode(x);
    newn->next = top;
    top = newn;
    printf("%d pushed to stack.\n", x);
}
int pop() {
    if (top == NULL) {
        printf("Stack Underflow! ");
        return 0;
    }
    struct node *temp = top;
    int val = temp->data;
    top = top->next;
    free(temp);
    return val;
}
int seek() {
    if (top == NULL) {
        printf("Stack is empty! ");
        return 0;
    }
    return top->data;
}

void display() {
    struct node* t = top;
    if (t == NULL) {
        printf("Stack empty!\n");
        return;
    }
    printf("STACK: ");
    while (t != NULL) {
        printf("%d -> ", t->data);
        t = t->next;
    }
    printf("NULL\n");
}

int main() {
    int choice, val, result;
    while (1) {
        printf("\n1)Push\n2)Pop\n3)Seek\n4)Display\n5)Exit\nChoice: ");
        if(!scanf("%d",&choice)){
        	printf("Invalid input!\n");
        	return 0;
		}
        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &val);
                push(val);
                break;
            case 2:
                result = pop();
                if (result != INT_MIN) 
                    printf("Popped Value: %d\n", result);
                break;
            case 3:
                result = seek();
                if (result != INT_MIN) 
                    printf("Top Value: %d\n", result);
                break;
            case 4:
                display();
                break;
            case 5:
                return 0;
            default:
                printf("Invalid choice!\n");
                return 0;
        }
    }
}
