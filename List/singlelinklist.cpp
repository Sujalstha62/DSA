#include<iostream>
using namespace std;
struct node{
	int data;
	node *next;
}*t,*start=NULL;
void addfirst(){
	int x;
	t=start;
	cout<<"Enter a value:";
	cin>>x;
	node* newn = new node;
	newn->data=x;
	newn->next=start;
	start=newn;
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
	while(i<index-2 && t->next!=NULL){
		t=t->next;
		i++;
	}
	newn->next=t->next;
	t->next=newn;
}
void addlast(){
	int x;
	t=start;
	cout<<"Enter a value:";
	cin>>x;
	node* newn = new node;
	newn->data=x;
	newn->next=NULL;
	if (start == NULL) {
        start = newn;
        return;
    }
	while(t->next!=NULL){
		t=t->next;
	}
	t->next=newn;
}
int removefirst(){
	int x;
	if(start == NULL){
		cout<<"List is empty\n";
		return 0;
	}
	node *temp = start;
	x = start->data;
	start = start->next;
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
        node *temp = start;
        x = temp->data;
        start = start->next;
        delete temp;
        return x;
    }
    node *temp = start;
    while(i < idx - 2){
        if(temp->next == NULL){
            cout << "Invalid position\n";
            return 0;
        }
        temp = temp->next;
        i++;
    }
    if(temp->next == NULL){
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
    if (start->next == NULL) {
    	x=start->data;
        delete start;
        start = NULL;
        return x;
    }
    node *temp = start;
    while (temp->next->next != NULL)
        temp = temp->next;
	x=temp->next->data;
	delete temp->next;
	temp->next=NULL;
    return x;
}
void add(){
	while(true){
		char ch;
		cout<<"\n1)Add newnode at beginning\n2)Add new node in between\n3)Add new node at last\nAny key to exit\nEnter your choice:";
		cin>>ch;
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
		cout<<"List empty!!\n";
	}
	t=start;
	cout<<"LIST\n";
	while(t!=NULL){
			cout<<t->data<<" ";
			t=t->next;
	}
	return;
}
int main(){
	int ch,x;
	cout<<"\n1)Create a node\n2)Terminate\nEnter your choice:";
	cin>>ch;
	switch(ch){
		case 1:
			cout<<"Enter a value:";
			cin>>x;
			start= new node;
			start->data=x;
			start->next=NULL;
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
