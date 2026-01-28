#include<iostream>
using namespace std;
void  insertion(int a[],int n){
	int i=1;
	int j;
	while (i<n-1){
		i++;
		int comp=a[i];
		j=i;
		while(j>0 && a[j-1]>comp){
			int temp=a[j-1];
			a[j-1]=comp;
			a[j]=temp;
			j--;
		}
	}
}
int main(){
	int n;
	cout<<"Enter no of terms:";
	cin>>n;
	int a[n];
	cout<<"Enter values:";
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	insertion(a,n);
	for(int i=0;i<n;i++){
		cout<<a[i]<<"\t";
	}
}
