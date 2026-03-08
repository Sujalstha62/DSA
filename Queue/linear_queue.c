#include<stdio.h>
#include<stdbool.h>
#define N 2
struct linqueue{
    int top;
    int bottom;
    int arr[N];
};
void init(struct linqueue *q){
    q->top=-1;
    q->bottom=-1;
}
bool isFull(struct linqueue *q){
    return (q->top==N-1);
}
bool isEmpty(struct linqueue *q){
    return (q->top==-1 || q->top<=q->bottom);
}
void enqueue(struct linqueue *q,int n){
    if(isFull(q)){
        printf("Queue full!!\n");
        return;
    }
    q->arr[++(q->top)]=n;
    printf("%d enqueued.\n", n);
}
int dequeue(struct linqueue *q){
    if(isEmpty(q)){
        printf("Queue Empty!!\n");
        return 0;
    }
    return q->arr[++(q->bottom)];
}
void show(struct linqueue *q){
	printf("QUEUE elements\n");
	int i=0;
	while((q->bottom+i)!=q->top){
		printf("%d\n",q->arr[(q->bottom)+ ++i]);
	}
}
int main(){
    struct linqueue A;
    init(&A);
    int ch,x;
    printf("Choose operation:");
    while(1){
        printf("\n1.Enqueue\n2.Dequeue\n3.Check if Queue empty\n4.Check if Queue full\n5.Show\nEnter your choice: ");
        if(!scanf("%d",&ch))break;
        switch(ch){
            case 1:
                printf("Enter a number: ");
                scanf("%d",&x);
                enqueue(&A,x);
                break;
            case 2:
                x=dequeue(&A);
                if(!isEmpty(&A))
                printf("%d Dequeued\n",x);
                break;
            case 3:
                if(isEmpty(&A))
				printf("Queue empty!!\n");
                else printf("Queue not empty!!\n");
                break;
            case 4:
                if(isFull(&A))
				printf("Queue full!!\n");
                else printf("Queue not full!!\n");
                break;
            case 5:
            	show(&A);
            	break;
            default:
                printf("Invalid input program terminated!!\n");
                return 0;
        }
    }
    return 0;
}
