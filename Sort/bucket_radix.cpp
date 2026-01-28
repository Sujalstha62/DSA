#include<iostream>
#include<vector>
using namespace std;
void sort(int a[],int b[],int div,int n){
	int c=0;
	for(int i=0;i<=9;i++){
		for(int j=0;j<n;j++){
			if((a[j]/div)%10==i){
				b[c]=a[j];
				c++;
			}
		}
	}
}
void bucket(int a[],int b[],int n){
	int max=0,d=1;
	for(int i=0;i<n;i++){
		if (a[i]>max){
			max=a[i];
		}
	}
	int div=1;
	for(int i=0;i<max;i++){
		sort(a,b,div,n);
		div*=10;
		for (int i = 0; i < n; i++) {
	        int temp = a[i];
	        a[i] = b[i];
	        b[i] = temp;
    	}
	}
}
int  main(){
	int n;
	cout<<"Enter no. of terms:";
	cin>>n;
	cout<<"Enter values:";
	int a[n],b[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	bucket(a,b,n);
	for(int i=0;i<n;i++){
		cout<<a[i]<<"\t";
	}
}
