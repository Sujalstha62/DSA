#include<iostream>
using namespace std;
int main(){
	int n,find;
	cout<<"Enter no of terms:";
	cin>>n;
	int a[n];
	cout<<"Enter values:";
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	cout<<"Enter the no to find:";
	cin>>find;
	for(int i=0;i<n;i++){
		if(a[i]==find){
			cout<<"Found at position "<<i+1;
			break;
		}
	if(i==n-1){
		cout<<find<<" doesn't exist";
	}
	}
}
