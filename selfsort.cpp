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
	int i,x,t=n,low=0;
	Stack A(n);
	while(n-low>1){
		A.push(low);
		for(i=low+1;i<n;i++){
			if(a[i]>=a[A.peek()])
				A.push(i);
		}
		i--;
		x=A.peek();
		while(a[i]==a[x]){
			n--;
			i--;
			x=A.pop();
			x=A.peek();
		}
		while(!A.isempty() && i>low){
			x=A.pop();
			while(a[i]>a[x] && i!=0)i--;
			if(i!=0){
				int temp=a[i];
				a[i]=a[x];
				a[x]=temp;
				i--;
			}
		}
		A.push(n-1);
		for(i=n-2;i>=low;i--){
			if(a[i]<=a[A.peek()])
				A.push(i);
		}
		i=low;
		x=A.peek();
		while(a[i]==a[x]){
			low++;
			i++;
			x=A.pop();
			x=A.peek();
		}
		while(!A.isempty() && i<n){
			x=A.pop();
			while(a[i]<a[x] && i!=n-1)i++;
			if(i!=n-1){
				int temp=a[i];
				a[i]=a[x];
				a[x]=temp;
				i++;
			}
		}
		for(int i=0;i<t;i++)
		cout<<a[i]<<" ";
		cout<<endl;
	}
}
int main(){
	int n=0,a[N];
	cout<<"Enter values:";
	while(cin>>a[n++]);
	n--;
	stacksort(a,n);
	cout<<endl<<"Final Sorted array!!\n";
	for(int i=0;i<n;i++)
		cout<<a[i]<<"\t";
}
