#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *next;
    struct node *prev;
};
struct node *start=NULL;
struct node* createNode(int val){
    struct node* newn=(struct node*)malloc(sizeof(struct node));
    if(newn==NULL){
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newn->data=val;
    newn->next=NULL;
    newn->prev=NULL; 
    return newn;
}
void addfirst(){
    int x;
    printf("Enter a value: ");
    scanf("%d", &x);
    struct node* newn=createNode(x);   
    if(start !=NULL){
        newn->next=start;
        start->prev=newn;
    }
    start=newn;
}
void addinbetween(){
    int x, index, i=1;
    if(start==NULL){
        printf("List is empty, adding at first.\n");
        addfirst();
        return;
    }
    printf("Enter position(1-based)and value: ");
    scanf("%d %d", &index, &x);
    if(index <=1){
        addfirst();
        return;
    }
    struct node* t=start;
    while(i < index - 1 && t->next !=NULL){
        t=t->next;
        i++;
    }
    struct node* newn=createNode(x);
    newn->next=t->next;
    newn->prev=t;
    if(t->next !=NULL)
    t->next->prev=newn;
    t->next=newn;
}
void addlast(){
    int x;
    printf("Enter a value: ");
    scanf("%d", &x);
    struct node* newn=createNode(x);
    if(start==NULL){
        start=newn;
        return;
    }
    struct node* t=start;
    while(t->next !=NULL)t=t->next;   
    t->next=newn;
    newn->prev=t;
}
int removefirst(){
	int x;
    if(start==NULL){
        printf("List is empty\n");
        return 0;
    }
    struct node *temp=start;
    x=temp->data;   
    start=start->next;
    if(start !=NULL)start->prev=NULL;
    free(temp);
    return x;
}
int removebetween(){
    int idx, i=1,x;
    if(start==NULL){
        printf("List empty\n");
        return 0;
    }
    printf("Enter the position of node to remove: ");
    scanf("%d", &idx);
    if(idx==1){
        x=removefirst();
        return x;
    }
    struct node *temp=start;
    while(i < idx && temp !=NULL){
        temp=temp->next;
        i++;
    }
    temp->prev->next=temp->next;
    if(temp->next !=NULL)
    temp->next->prev=temp->prev;
    x=temp->data;
    free(temp);
    return x;
}
int removelast(){
	int x;
    if(start==NULL){
        printf("List is empty\n");
        return 0;
    }
    struct node *temp=start;
    if(start->next==NULL){
    	x=start->data;
        free(start);
        start=NULL;
        return x;
    }
    while(temp->next !=NULL)temp=temp->next;   
    x=temp->data;
    temp->prev->next=NULL;
    free(temp);
    return x;
}
void display(){
    struct node* t=start;
    if(t==NULL){
        printf("List empty!!\n");
        return;
    }
    printf("LIST(Forward):  ");
    while(t !=NULL){
        printf("%d <-> ", t->data);
        t=t->next;
    }
    printf("NULL\n");
}
int main(){
    int choice, subChoice;
    while(1){
        printf("\n1)Add Node\n2)Remove Node\n3)Display\n4)Exit\nChoice: ");
        if(scanf("%d", &choice)!=1)break;
        switch(choice){
            case 1:
                printf("\n1)Beginning\n2)In-between\n3)Last\nChoice: ");
                scanf("%d", &subChoice);
                if(subChoice==1)addfirst();
                else if(subChoice==2)addinbetween();
                else if(subChoice==3)addlast();
                break;
            case 2:
                printf("\n1)Beginning\n2)In-between\n3)Last\nChoice: ");
                scanf("%d", &subChoice);
                if(subChoice==1)printf("Removed: %d",removefirst());
                else if(subChoice==2)printf("Removed: %d",removebetween());
                else if(subChoice==3)printf("Removed: %d",removelast());
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
