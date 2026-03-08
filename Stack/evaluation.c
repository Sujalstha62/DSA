#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#define MAX 20
struct Stack{
    double st[MAX];
    int top;
};
void initStack(struct Stack *s){
    s->top=-1;
}
void push(struct Stack *s,double value){
    if(s->top<MAX-1)s->st[++(s->top)]=value;
}
double pop(struct Stack *s){
    if(s->top!=-1)return s->st[(s->top)--];
}
int isop(char op){
    return (op=='+' || op=='-' || op=='*' || op=='/' || op=='$');
}
double calculate(double op1,double op2,char op){
    switch(op){
        case '+': return op1+op2;
        case '-': return op1-op2;
        case '*': return op1*op2;
        case '/': return op1/op2;
        case '$': return pow(op1,op2);
        default: return 0;
    }
}
void evaluatePostfix(char *exp){
	int i;
    struct Stack s;
    initStack(&s);
    int len=strlen(exp);
    if(isop(exp[0])){
        printf("Prefix expression detected!!\n");
        return;
    }
    for(i=0;i<len;i++){
        if(isdigit(exp[i]))
		push(&s,(double)(exp[i]-'0'));
		else if(isop(exp[i])){
            double o2=pop(&s);
            double o1=pop(&s);
            push(&s,calculate(o1,o2,exp[i]));
        }
		else{
            printf("Invalid input.... Program terminated!!\n");
            return;
        }
    }
    printf("Result = %.2f\n\n", pop(&s));
}
void evaluatePrefix(char *exp){
	int i;
    struct Stack s;
    initStack(&s);
    int len=strlen(exp);
    if(isop(exp[len-1])){
        printf("Postfix expression detected!!\n");
        return;
    }
    for(i=len-1;i>=0;i--){
        if(isdigit(exp[i]))
        push(&s,(double)(exp[i]-'0'));
		else if(isop(exp[i])){
            double o1=pop(&s);
            double o2=pop(&s);
			push(&s,calculate(o1,o2,exp[i]));
        }
		else{
            printf("Invalid input.... Program terminated!!\n");
            return;
        }
    }
    printf("Result = %.2f\n\n",pop(&s));
}
int main(){
    char exp[MAX];
    int choice;
    while(1){
        printf("1. Postfix\n2. Prefix\nAny other key to Exit\nEnter choice: ");
        if(!scanf("%d",&choice))break;
        printf("Enter expression: ");
        scanf("%s",exp);
        switch(choice){
            case 1:
                evaluatePostfix(exp);
                break;
            case 2:
                evaluatePrefix(exp);
                break;
            default:
                printf("Invalid Input program terminated!!\n");
                return 0;
        }
    }
    return 0;
}
