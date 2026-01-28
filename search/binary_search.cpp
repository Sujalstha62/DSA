#include<iostream>
using namespace std;
void selection(int a[], int n){
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			if(a[i]>a[j]){
				int temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
		}
	}
}
void binsearch(int a[],int x,int p,int q){
	int search=p+(p-q)/2;
	if(p>q){
		cout<<x<<" doesn't exist!!";
		return;
	} 
	if(a[search]==x){
		cout<<"Found at position "<<search+1;
		return;
	}
	else if(x<a[search]){
		binsearch(a,x,p,search);
	}
	else{
		binsearch(a,x,search+1,q);
	}
}
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
	selection(a,n);
	cout<<"sorted array"<<endl;
	for(int i=0;i<n;i++){
		cout<<a[i]<<"\t";
	}
	cout<<endl;
	binsearch(a,find,0,n-1);
}
