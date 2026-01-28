#include<iostream>
using namespace std;
int main(){
	int n;
	cout<<"Enter no of terms:";
	cin>>n;
	int a[n];
	cout<<"Enter values:";
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		int min=i;
		for(int j=i+1;j<n;j++){
			if(a[min]>a[j]){
				min=j;
			}
		}
		int t=a[i];
		a[i]=a[min];
		a[min]=t;
	}
	for(int i=0;i<n;i++){
		cout<<a[i]<<"\t";
	}
}

