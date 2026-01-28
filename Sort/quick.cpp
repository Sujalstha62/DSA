#include<iostream>
using namespace std;
int part(int a[],int p,int q){
	int pivot = a[p];
	int i = p-1;
	int j = q+1;
	while(true){
		do{
			i++;	
		}while(a[i]<pivot);
		do{
			j--;	
		}while(a[j]>pivot);
		if(i>=j){
			return j;
		}
		int temp = a[i];
		a[i] = a[j];
		a[j] = temp;
	}
}
void quickSort(int a[],int p,int q,int n){
	if(p<q){
		int separate = part(a,p,q);
		quickSort(a,p,separate,n);
		quickSort(a,separate+1,q,n);
	}
}
void Quick_sort(int a[],int n){
	quickSort(a,0,n-1,n);
}
int main(){
	int n;
	cout<<"Enter size of array : ";
	cin>>n;
	int a[n];
	cout<<"Enter elements in array : ";
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	Quick_sort(a,n);
	cout<<"Sorted elements in array : ";
	for(int i=0;i<n;i++){
		cout<<a[i]<<"\t";
	}
return 0;
}
