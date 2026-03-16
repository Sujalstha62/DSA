#include<iostream>
#define N 100
using namespace std;
class Stack {
    int st[N];
    int top;
    int max;
public:
	Stack(){
		max=0;
		top=-1;
	}
	Stack(int v){
		max=(v>N)?N:v;
		top=-1;
	}
	bool isfull(){
		return top==max-1;
	}
	bool isempty(){
		return top==-1;
	}
    void push(int value) {
        if (!isfull()) 
            st[++top] = value;
    }
    int pop() {
        if (!isempty())
            return st[top--];
    }
    int peek() {
        if (!isempty())
            return st[top];
    }
};
void stacksort(int a[],int n){
	int i,x;
	Stack A(n);
	while(n>1){
		A.push(0);
		for(i=1;i<n;i++){
			if(a[i]>a[A.peek()])
				A.push(i);
		}
		while(!A.isempty()){
			x=A.pop();
			while(a[i]==a[x]){
				n--;
				i--;
				x=A.pop();
			}
			while(a[i]>a[x] && i!=0)i--;
			if(i!=0){
				int temp=a[i];
				a[i]=a[x];
				a[x]=temp;
			}
		}
		n--;
	}
}
int main(){
	int n,a[N];
	cout<<"Enter no of terms:";
	cin>>n;
	cout<<"Enter values:";
	for(int i=0;i<n;i++)
		cin>>a[i];
	stacksort(a,n);
	for(int i=0;i<n;i++)
		cout<<a[i]<<"\t";
}
