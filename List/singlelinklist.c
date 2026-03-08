#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node *start=NULL;
struct node* createNode(int val){
    struct node* newn=(struct node*)malloc(sizeof(struct node));
    if(newn == NULL){
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newn->data=val;
    newn->next=NULL;
    return newn;
}
void addfirst(){
    int x;
    printf("Enter a value:");
    scanf("%d",&x);
    struct node* newn=createNode(x);
    newn->next=start;
    start=newn;
}
void addinbetween(){
    int x,index,i=1;
    if(start==NULL){
        addfirst();
        return;
    }
    printf("Enter position(1-based) and value: ");
    scanf("%d %d",&index,&x);    
    if(index<=1){
        struct node* newn=createNode(x);
        newn->next=start;
        start=newn;
        return;
    }
    struct node* t=start;
    while(i<index-1 && t->next!=NULL){
        t=t->next;
        i++;
    }   
    struct node* newn=createNode(x);
    newn->next=t->next;
    t->next=newn;
}
void addlast(){
    int x;
    printf("Enter a value:");
    scanf("%d",&x);
    struct node* newn=createNode(x);   
    if(start==NULL){
        start=newn;
        return;
    }
    struct node* t=start;
    while(t->next != NULL)t=t->next;
    t->next=newn;
}
int removefirst(){
	int x;
    if(start == NULL){
        printf("List is empty\n");
        return;
    }
    struct node *temp=start;
    x=temp->data;
    start=start->next;
    free(temp);
    return x;
}
int removebetween(){
    int idx,i=1,x;
    if(start == NULL){
        printf("List empty\n");
        return 0;
    }
    printf("Enter the position of node to remove:");
    scanf("%d",&idx);
    if(idx == 1){
        x=removefirst();
        return x;
    }
    struct node *temp=start;
    struct node *prev=NULL;
    while(i<idx && temp!=NULL){
        prev=temp;
        temp=temp->next;
        i++;
    }
    if(temp == NULL){
        printf("Invalid position\n");
        return 0;
    }
    prev->next=temp->next;
    x=temp->data;
    free(temp);
    return x;
}
int removelast(){
	int x;
    if(start==NULL){
        printf("List is empty\n");
        return;
    }
    if(start->next==NULL){
    	x=start->data;
        free(start);
        start=NULL;
        return x;
    }
    struct node *temp=start;
    while(temp->next->next!=NULL)temp=temp->next; 
	x=temp->next->data;
    free(temp->next);
    temp->next=NULL;
    return x;
}
void display(){
    struct node* t=start;
    if(t==NULL){
        printf("List empty!!\n");
        return;
    }
    printf("LIST:");
    while(t != NULL){
        printf("%d->",t->data);
        t=t->next;
    }
    printf("NULL\n");
}
int main(){
    int choice;
    while(1){
        printf("\n--- Linked List Menu ---\n");
        printf("1)Add Node\n2)Remove Node\n3)Display\n4)Exit\nChoice:");
        if(!scanf("%d",&choice)){
        	printf("Invalid input!!\n");
        	break;
		}
        switch(choice){
            case 1:
                printf("\n1)Beginning\n2)In-between\n3)Last\nChoice:");
                scanf("%d",&choice);
                if(choice==1)addfirst();
                else if(choice==2)addinbetween();
                else if(choice==3)addlast();
                break;
            case 2:
                printf("\n1)Beginning\n2)In-between\n3)Last\nChoice:");
                scanf("%d",&choice);
                if(choice==1)printf("Removed:%d\n",removefirst());
                else if(choice==2)printf("Removed:%d\n",removebetween());
                else if(choice==3)printf("Removed:%d\n",removelast());
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
