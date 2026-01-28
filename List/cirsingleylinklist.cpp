#include<iostream>
using namespace std;
struct node{
	int data;
	node *next;
}*t,*start=NULL;
node* getLastNode() {
    if (start == NULL) return NULL;
    node* temp = start;
    while (temp->next != start) {
        temp = temp->next;
    }
    return temp;
}
void addfirst(){
	int x;
	cout<<"Enter a value:";
	cin>>x;
	node* newn = new node;
	newn->data=x;
	if(start==NULL){
		start=newn;
		newn->next=start;
	}
	else{
		t=getLastNode();
		newn->next=start;
		start=newn;
		t->next=start;
	}
}
void addinbetween(){
	int x;
	if(start == NULL){
        cout << "List is empty\n";
        return;
    }
	t=start;
	int index,i=0;
	cout<<"Enter postition and value:";
	cin>>index>>x;
	if(index == 0){
        addfirst();
        return;
    }
	node* newn= new node;
	newn->data=x;
	while(i<index-2 && t->next!=start){
		t=t->next;
		i++;
	}
	newn->next=t->next;
	t->next=newn;
}
void addlast(){
	int x;
	cout<<"Enter a value:";
	cin>>x;
	node* newn = new node;
	newn->data=x;
	newn->next=start;
	if (start == NULL) {
        start = newn;
        return;
    }
	t=getLastNode();
	t->next=newn;
}
int removefirst(){
	int x;
	if(start == NULL){
		cout<<"List is empty\n";
		return 0;
	}
	node *temp = start;
	x=start->data;
	if(start->next==start){
		delete start;
		start=NULL;
		return x;
	}
	t=getLastNode();
	start = start->next;
	t->next=start;
	delete temp;
	return x;
}
int removebetween(){
	int x;
    int idx, i = 0;
    cout << "Enter the position of node to remove:";
    cin >> idx;
    if(idx < 1){
        cout << "Error input!\n";
        return 0;
    }
    if(start == NULL){
        cout << "List empty\n";
        return 0;
    }
    if(idx == 1){
        x=removefirst();
        return x;
    }
    node *temp = start;
    while(i < idx - 2){
        if(temp->next == start){
            cout << "Invalid position\n";
            return 0;
        }
        temp = temp->next;
        i++;
    }
    if(temp->next == start){
        cout << "Invalid position\n";
        return 0;
    }
    node* del = temp->next;
    x = del->data;
    temp->next = del->next;
    delete del;
    return x;
}
int removelast() {
	int x;
    if (start == NULL) {
        cout << "List is empty\n";
        return 0;
    }
    if (start->next == start) {
    	x=removefirst();
    	return x;
    }
    t=start;
    while (t->next->next != start) {
        t = t->next;
    }
    x=t->next->data;
    delete t->next;
    t->next=start;
    return x;
}
void add(){
	while(true){
		char ch;
		cout<<"\n1)Add newnode at beginning\n2)Add new node in between\n3)Add new node at last\nAny key to exit\nEnter your choice:";
		cin>>ch;
		t=start;
		switch(ch){
			case '1':
				addfirst();
				break;
			case '2':
				addinbetween();
				break;
			case '3':
				addlast();
				break;
			default:
				return;
		}
	}
}
void remove(){
	while(true){
		char ch;
		cout<<"\n1)Remove node from beginning\n2)Remove node from between\n3)Remove node from last\nAny key to exit\nEnter your choice:";
		cin>>ch;
		switch(ch){
			case '1':
				removefirst();
				break;
			case '2':
				removebetween();
				break;
			case '3':
				removelast();
				break;
			default:
				return;
		}
	}
}
void display(){
	if(start==NULL){
		cout<<"List is empty!!\n";
		return;
	}
	t=start;
	cout<<"LIST\n";
	do{
		cout<<t->data<<" ";
		t=t->next;
	}while(t!=start);
	return;
}
int main(){
	int ch,x;
	cout<<"\n1)Create a node\n2)Terminate\nEnter your choice:";
	cin>>ch;
	switch(ch){
		case 1:
			addfirst();
			break;
		default:
			cout<<"Program terminated!!"<<endl;
			return 0;
	}
	while(true){
		cout<<"\n1)Add node\n2)Remove node\n3)Display\nEnter your choice:";
		cin>>ch;
		switch(ch){
			case 1:
				add();
				break;
			case 2:
				remove();
				break;	
			case 3:
				display();
				break;
			default:
				cout<<"Thankyou!!";
				return 0;
		}
	}
	
}
