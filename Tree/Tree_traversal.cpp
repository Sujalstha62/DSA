#include<iostream>
#include<cctype>
using namespace std;
#define N 20
class node{
	public:
	char data;
	node *left;
	node *right;
	node(char value){
		data=value;
		left= NULL;
		right= NULL;
	}
}*start=NULL;
class cirqueue{
	int top,bottom;
	node* arr[N];
	public:
		cirqueue(){
			top=bottom=-1;
		}
		void enqueue(node* n){
			if(top==N-1 && bottom==-1){
				return;
			}
			if(top-bottom<N){
				top++;
				arr[top%N]=n;	
			}
		}
		node* dequeue(){
			if(top==bottom){
				return NULL;
			}
			bottom++;
			return arr[bottom%N];
		}
		node* peek(){
			if(top==bottom){
				return NULL;
			}
			return arr[bottom%N];
		}
};
class heap_tree{
	public:
	cirqueue A;
	int count;
	node *root=NULL;
	heap_tree(){
		start=NULL;
		root=start;
		count=0;
	}
	void insert(char value){
		if(root==NULL){
			root= new node(value);
			start=root;
			A.enqueue(root);
			count=1;
		}
		else{
			if(count%2==0) root=A.peek();
			else root=A.dequeue();
			if(root->left==NULL){
				root->left= new node(value);
				root=root->left;
				root->left=NULL;
				root->right=NULL;
				A.enqueue(root);
				count++;
				return;
			}
			else{
				root->right= new node(value);
				root=root->right;
				root->left=NULL;
				root->right=NULL;
				A.enqueue(root);
				count++;
				return;
			}
		}
	}
	void displaypre(node *t){
		cout<<t->data<<"\t";
		if(t->left!=NULL){
			displaypre(t->left);
		}
		if(t->right!=NULL){
			displaypre(t->right);
		}
	}
	void displaypost(node *t){
		if(t->left!=NULL){
			displaypost(t->left);
		}
		if(t->right!=NULL){
			displaypost(t->right);
		}
		cout<<t->data<<"\t";
	}
	void displayin(node *t){
		if(t->left!=NULL){
			displayin(t->left);
		}
		cout<<t->data<<"\t";
		if(t->right!=NULL){
			displayin(t->right);
		}
	}
};
int main(){
	heap_tree *A;
	char ch,x,order;
	do{
		A = new heap_tree;
		cout<<"Enter data:";
		while(1){
			cin>>x;
			if(isalnum(x))A->insert(x);
			else break;
		}
		while(1){
			cout<<"\n1)Inorder\n2)Postorder\n3)Preorder\nEnter your choice:";
			cin>>order;
				if(order=='1')A->displayin(start);
				else if(order=='2')A->displaypost(start);
				else if(order=='3')A->displaypre(start);
				else break;
		}
		cout<<"\nEnter 'Y' for new session:";
		cin>>ch;
	}while(ch=='y' || ch=='Y');
}
