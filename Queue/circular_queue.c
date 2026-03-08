#include <stdio.h>
#include <stdbool.h>
#define N 2
struct cirqueue {
    int top;
    int bottom;
    int arr[N];
};
void init(struct cirqueue *q) {
    q->top = -1;
    q->bottom = -1;
}
bool isEmpty(struct cirqueue *q) {
    return (q->top == q->bottom);
}
bool isFull(struct cirqueue *q) {
    return (q->top - q->bottom >= N);
}
void enqueue(struct cirqueue *q, int n) {
    if (isFull(q)) {
        printf("Queue full!!\n");
        return;
    }
    q->top++;
    q->arr[q->top % N] = n;
    printf("%d enqueued.\n", n);
}
int dequeue(struct cirqueue *q) {
    if (isEmpty(q)) {
        printf("Queue Empty!!\n");
        return 0;
    }
    q->bottom++;
    return q->arr[q->bottom % N];
}
void show(struct cirqueue *q){
	printf("QUEUE elements\n");
	int i=0;
	while((q->bottom+i)!=q->top){
		printf("%d\n",q->arr[(q->bottom+ ++i)%N]);
	}
}
int main() {
    struct cirqueue A;
    init(&A);
    int ch, x;
    printf("Choose operation:");
    while (1) {
        printf("\n1.Enqueue\n2.Dequeue\n3.Check if empty\n4.Check if full\n5.Show\nEnter choice: ");
        if (!scanf("%d", &ch)) break;
        switch (ch) {
            case 1:
                printf("Enter a number:");
                scanf("%d", &x);
                enqueue(&A, x);
                break;
            case 2:
                x = dequeue(&A);
                if (x != 0 || !isEmpty(&A))
                    printf("%d Dequeued\n", x);
                break;
            case 3:
                if (!isEmpty(&A)) printf("Queue not empty!!\n");
                else printf("Queue empty!!\n");
                break;
            case 4:
                if (isFull(&A)) printf("Queue full!!\n");
                else printf("Queue not full!!\n");
                break;
            case 5:
            	show(&A);
            	break;
            default:
                printf("Invalid input, program terminated!!\n");
                return 0;
        }
    }
    return 0;
}
