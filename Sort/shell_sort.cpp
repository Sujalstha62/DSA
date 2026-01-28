#include<iostream>
using namespace std;
void shell_sort(int a[],int n){
	int gap=n;
	while(gap!=1){
//			cout<<endl<<endl;
		int comp;
		gap=gap/2;
		int i=0;
		while(i+gap<n){
			if(a[gap+i]<a[i]){
				int temp=a[i];
				a[i]=a[gap+i];
				a[gap+i]=temp;
//				for(int l=0;l<n;l++){
//					cout<<a[l]<<"\t";
//				}
//				cout<<endl;
			}
			int j=i;
			comp=a[i];
			while(j-gap>=0 && a[j-gap]>comp){
				int temp=a[j-gap];
				a[j-gap]=comp;
				a[j]=temp;
				j-=gap;
//				for(int l=0;l<n;l++){
//					cout<<a[l]<<"\t";
//				}
//				cout<<endl;
			}	
			i++;
		}
	}
}
int main(){
	int N;
	cout<<"Enter the size of array:";
	cin>>N;
	int arr[N];
	cout<<"Enter values:";
	for(int i=0;i<N;i++){
		cin>>arr[i];
	}
	shell_sort(arr,N);
	cout<<"Sorted array!!\n";
	for(int i=0;i<N;i++){
		cout<<arr[i]<<"\t";
	}
}
