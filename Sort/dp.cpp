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
	for(int i=0;i<n-i;i++){
		int min=i;
		int max=n-i-1;
		for(int j=i+1;j<n-i;j++){
			if(a[min]>a[j]){
				min=j;
			}
			if(a[max]<a[n-j-1]){
				max=n-j-1;
			}
		}
		int t2=a[n-i-1];
		a[n-i-1]=a[max];
		a[max]=t2;
		int t1=a[i];
		if(t1!=a[max]){
		a[i]=a[min];
		a[min]=t1;
		}
		
	}
	for(int i=0;i<n;i++){
		cout<<a[i]<<"\t";
	}
}

