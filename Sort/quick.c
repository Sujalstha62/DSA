#include<stdio.h>
#define N 30
int part(int a[],int p,int q){
	int pivot=a[p],temp;
	int i=p-1;
	int j=q+1;
	while(1){
		do{i++;}while(a[i]<pivot);
		do{j--;}while(a[j]>pivot);
		if(i>=j) return j;
		temp=a[i];
		a[i]=a[j];
		a[j]=temp;
	}
}
void quickSort(int a[],int p,int q,int n){
	int separate;
	if(p<q){
		separate=part(a,p,q);
		quickSort(a,p,separate,n);
		quickSort(a,separate+1,q,n);
	}
}
void Quick_sort(int a[],int n){
	quickSort(a,0,n-1,n);
}
int main(){
	int i,n,a[N];
	printf("Enter size of array : ");
	scanf("%d",&n);
	printf("Enter elements in array : ");
	for(i=0;i<n;i++) scanf("%d",&a[i]);
	Quick_sort(a,n);
	printf("Sorted elements in array : ");
	for(i=0;i<n;i++) printf("%d\t",a[i]);
}
