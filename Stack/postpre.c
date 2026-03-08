#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include<ctype.h>
#define MAX 50
struct Stack{
    char st[MAX];
    int top;
};
bool isempty(struct Stack *s){
    return s->top==-1;
}
bool isfull(struct Stack *s){
	return s->top==MAX-1;
}
void push(struct Stack *s,char val){
    if(!isfull(s))s->st[++(s->top)]=val;
}
char pop(struct Stack *s){
    if(!isempty(s))return s->st[(s->top)--];
    return '\0';
}
char peek(struct Stack *s){
    if(!isempty(s))return s->st[s->top];
    return '\0';
}
int priority(char op){
    if(op=='$') return 3;
    if(op=='/' || op=='*')return 2;
    if(op=='-' || op=='+')return 1;
    return 0;
}
void reverse(char* exp){
	int i;
    int n=strlen(exp);
    for(i=0;i<n/2;i++){
        char temp=exp[i];
        exp[i]=exp[n-i-1];
        exp[n-i-1]=temp;
    }
}
void infixToPostfix(char* infix, char* postfix){
	int i;
    struct Stack s;
    s.top=-1;
    int k=0;
    for(i=0;infix[i]!='\0';i++) {
        char ch=infix[i];
        if(isalnum(ch))postfix[k++]=ch;
		else if(ch=='(')push(&s,'(');
		else if(ch==')'){
            while(!isempty(&s) && peek(&s) != '(')
			postfix[k++]=pop(&s);
            pop(&s);
        }
		else{
            while(!isempty(&s) && priority(peek(&s)) >= priority(ch))
			postfix[k++]=pop(&s);
            push(&s,ch);
        }
    }
    while(!isempty(&s))postfix[k++]=pop(&s);
    postfix[k]='\0';
}
int main(){
    char infix[MAX],result[MAX];
    int choice,i;
    while(1){
        printf("\n1.Postfix\n2.Prefix\nAny other key to Exit\nChoice:");
        if(!scanf("%d",&choice))break;
        printf("Enter expression:");
        scanf("%s",infix);
        if(choice==1){
            infixToPostfix(infix,result);
            printf("Postfix: %s\n",result);
        }
		else if(choice==2){
            reverse(infix);
            for(i=0;infix[i]!='\0';i++){
                if(infix[i]=='(')infix[i]=')';
                else if(infix[i]==')')infix[i]='(';
            }
            infixToPostfix(infix,result);
            reverse(result);
            printf("Prefix: %s\n",result);
        }
		else break;
    }
    return 0;
}
