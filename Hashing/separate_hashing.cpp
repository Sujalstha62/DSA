#include<iostream>
#include<vector>
#include<cctype>
using namespace std;
struct node{
	int data;
	node *next=NULL;
	node(){
		data=0;
	}
}*t;
void addlast(int x,node* &head){
	node* newn = new node;
	newn->data=x;
	newn->next=NULL;
	if (head == NULL) {
        head = newn;
        return;
    }
    t=head;
	while(t->next!=NULL){
		t=t->next;
	}
	t->next=newn;
}
void display(node* &a){
	t=a;
	while(t!=NULL){
		cout<<t->data<<" ";
		t=t->next;
	}
	return;
}
int main(){
	int n,i,hash,hash_key;
	vector <node*> arr;
	cout<<"Enter the number of available location:";
	cin>>n;
	arr.resize(n);
	cout<<"Enter numbers:";
	while(cin>>hash){
		hash_key=hash%n;
		addlast(hash,arr[hash_key]);
	}
	for(int i=0;i<n;i++){
		display(arr[i]);
		cout<<endl;
	}
}
