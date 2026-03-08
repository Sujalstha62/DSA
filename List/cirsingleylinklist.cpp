#include<iostream>
using namespace std;

struct node {
    int data;
    node *next;
} *t, *start = NULL;

// Helper function to find the tail of the list
node* getLastNode() {
    if (start == NULL) return NULL;
    node* temp = start;
    while (temp->next != start) {
        temp = temp->next;
    }
    return temp;
}

void addfirst() {
    int x;
    cout << "Enter a value: ";
    cin >> x;
    node* newn = new node;
    newn->data = x;
    
    if (start == NULL) {
        start = newn;
        newn->next = start; // Points to itself
    } else {
        node* tail = getLastNode();
        newn->next = start;
        start = newn;
        tail->next = start; // Tail must point to new start
    }
}

void addinbetween() {
    if (start == NULL) {
        cout << "List is empty, adding at first position...\n";
        addfirst();
        return;
    }
    
    int x, index, i = 1;
    cout << "Enter position (1-based) and value: ";
    cin >> index >> x;

    if (index <= 1) {
        // We can't easily call addfirst() here because it asks for 'x' again.
        // Simplified logic:
        node* newn = new node;
        newn->data = x;
        node* tail = getLastNode();
        newn->next = start;
        start = newn;
        tail->next = start;
        return;
    }

    t = start;
    // Traverse to the node before the target position
    while (i < index - 1 && t->next != start) {
        t = t->next;
        i++;
    }

    node* newn = new node;
    newn->data = x;
    newn->next = t->next;
    t->next = newn;
}

void addlast() {
    if (start == NULL) {
        addfirst();
        return;
    }
    int x;
    cout << "Enter a value: ";
    cin >> x;
    node* newn = new node;
    newn->data = x;
    
    node* tail = getLastNode();
    tail->next = newn;
    newn->next = start; // Complete the circle
}

int removefirst() {
    if (start == NULL) {
        cout << "List is empty\n";
        return 0;
    }
    int x = start->data;
    node *temp = start;

    if (start->next == start) { // Only one node
        delete start;
        start = NULL;
    } else {
        node* tail = getLastNode();
        start = start->next;
        tail->next = start; // Link tail to new head
        delete temp;
    }
    cout << "Removed: " << x << endl;
    return x;
}

int removebetween() {
    if (start == NULL) {
        cout << "List empty\n";
        return 0;
    }

    int idx, i = 1;
    cout << "Enter the position of node to remove: ";
    cin >> idx;

    if (idx <= 1) return removefirst();

    node *curr = start;
    node *prev = NULL;

    while (i < idx) {
        prev = curr;
        curr = curr->next;
        i++;
        if (curr == start) {
            cout << "Invalid position!\n";
            return 0;
        }
    }

    int x = curr->data;
    prev->next = curr->next;
    delete curr;
    cout << "Removed: " << x << endl;
    return x;
}

int removelast() {
    if (start == NULL) {
        cout << "List is empty\n";
        return 0;
    }
    if (start->next == start) return removefirst();

    t = start;
    node* prev = NULL;
    while (t->next != start) {
        prev = t;
        t = t->next;
    }
    int x = t->data;
    prev->next = start; // Penultimate node now points to start
    delete t;
    cout << "Removed: " << x << endl;
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
