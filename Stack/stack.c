#include<stdio.h>
#include<stdbool.h>
#define max 2
struct stack{
    int st[max];
    int top;
};
bool isfull(struct stack *s){
	if(s->top==max-1)return 1;
	else return 0;
}
bool isempty(struct stack *s){
	if(s->top==-1)return 1;
	else return 0;
}
void push(struct stack *s, int value){
    if(isfull(s))printf("Stack Overflow!\n");
	else{
        s->st[++(s->top)]=value;
        printf("%d pushed.\n",value);
    }
}
int pop(struct stack *s){
    if(isempty(s)){
		printf("Stack Underflow!\n");
	    return 0;
	}
    return s->st[s->top--];
}
int peek(struct stack *s){
    if(isempty(s)){
		printf("Stack is empty!\n");
		return 0;
	}
    else printf("Top element is %d\n",s->st[s->top]);
}
void show(struct stack *s){
	int i;
    if(isempty(s)){
        printf("Stack is empty!\n");
        return;
    }
    printf("Stack elements:\n");
    for(i=s->top;i>=0;i--)printf("%d\n",s->st[i]);
}
int main(){
    struct stack A;
    A.top=-1;
    int value,ch;
    while(1){
        printf("\n1.Push\n2.Pop\n3.Peek\n4.Isfull\n5.Isempty\n6.Show\n(Any other key to exit)\nEnter choice:");
        if(!scanf("%d",&ch))break;
        switch(ch){
            case 1:
                printf("Enter value:");
                scanf("%d",&value);
                push(&A,value);
                break;
            case 2:
                printf("Popped %d\n",pop(&A));
                break;
            case 3:
                printf("Top is %d\n",peek(&A));
                break;
            case 4:
            	if(isfull(&A))printf("Stack full\n");
            	else printf("Stack not full\n");
            	break;
            case 5:
            	if(isempty(&A))printf("Stack empty\n");
            	else printf("Stack not empty\n");
            	break;
			case 6:
                show(&A);
                break;
            default:
                return 0;
        }
    }
    return 0;
}
