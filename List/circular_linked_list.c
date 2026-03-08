#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node *start = NULL;
struct node* getLastNode(){
    if(start == NULL) return NULL;
    struct node* temp = start;
    while(temp->next != start) temp = temp->next;
    return temp;
}
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
    printf("Enter a value: ");
    scanf("%d", &x);
	struct node* newn =createNode(x);
    if(start == NULL){
        start = newn;
        newn->next = start;
    } else{
        struct node* tail = getLastNode();
        newn->next = start;
        start = newn;
        tail->next = start;
    }
}
void addinbetween(){
    if(start == NULL){
        printf("List is empty, adding at first position...\n");
        addfirst();
        return;
    }   
    int x, index, i = 1;
    printf("Enter position(1-based) and value: ");
    scanf("%d %d", &index, &x);
    if(index <= 1){
        addfirst();
        return;
    }
    struct node* t = start;
    while(i<index-1 && t->next!=start){
        t=t->next;
        i++;
    }
    struct node* newn =createNode(x);
    newn->next = t->next;
    t->next = newn;
}
void addlast(){
    if(start == NULL){
        addfirst();
        return;
    }
    int x;
    printf("Enter a value: ");
    scanf("%d", &x);
    struct node* newn =createNode(x);  
    struct node* tail = getLastNode();
    tail->next = newn;
    newn->next = start;
}
int removefirst(){
    if(start == NULL){
        printf("List is empty\n");
        return 0;
    }
    int x = start->data;
    struct node *temp = start;
    if(start->next == start){
        free(start);
        start = NULL;
    } else{
        struct node* tail = getLastNode();
        start = start->next;
        tail->next = start;
        free(temp);
    }
    return x;
}
int removebetween(){
    if(start == NULL){
        printf("List empty\n");
        return 0;
    }
    int idx, i = 1;
    printf("Enter the position of node to remove: ");
    scanf("%d", &idx);
    if(idx <= 1) return removefirst();
    struct node *curr = start;
    struct node *prev = NULL;
    while(i < idx){
        prev = curr;
        curr = curr->next;
        i++;
        if(curr == start){
            printf("Invalid position!\n");
            return 0;
        }
    }
    int x = curr->data;
    prev->next = curr->next;
    free(curr);
    return x;
}
int removelast(){
    if(start == NULL){
        printf("List is empty\n");
        return 0;
    }
    if(start->next == start) return removefirst();
    struct node* t = start;
    struct node* prev = NULL;
    while(t->next != start){
        prev = t;
        t = t->next;
    }
    int x = t->data;
    prev->next = start;
    free(t);
    return x;
}
void add_menu(){
    char ch;
    while(1){
        printf("\n--- ADD MENU ---\n1) Beginning\n2) Between\n3) Last\n4) Back\nChoice: ");
        scanf(" %c", &ch);
        if(ch == '1') addfirst();
        else if(ch == '2') addinbetween();
        else if(ch == '3') addlast();
        else return;
    }
}
void remove_menu(){
    char ch;
    while(1){
        printf("\n--- REMOVE MENU ---\n1) Beginning\n2) Between\n3) Last\n4) Back\nChoice: ");
        scanf(" %c", &ch);
        if(ch == '1') printf("Removed: %d",removefirst());
        else if(ch == '2') printf("Removed: %d",removebetween());
        else if(ch == '3') printf("Removed: %d",removelast());
        else return;
    }
}
void display(){
    if(start == NULL){
        printf("List is empty!!\n");
        return;
    }
    struct node* t = start;
    printf("LIST: ");
    do{
        printf("%d -> ", t->data);
        t = t->next;
    } while(t != start);
    printf("(head)\n");
}
int main(){
    int ch;
    printf("1) Create/Start List\n2) Exit\nChoice: ");
    if(!scanf("%d",&ch) || ch!=1) return 0;  
    addfirst();
    while(1){
        printf("\nMAIN MENU:\n1)Add\n2)Remove\n3)Display\n4)Exit\nChoice: ");
        if(!scanf("%d", &ch)) return 0;
        if(ch == 1) add_menu();
        else if(ch == 2) remove_menu();
        else if(ch == 3) display();
        else break;
    }
    printf("Exiting...\n");
    return 0;
}
