#include<stdio.h>
#define N 30
void shell_sort(int a[],int n){
	int i,j,comp,temp,gap=n;
	while(gap!=1){
		comp;
		gap=gap/2;
		i=0;
		while(i+gap<n){
			if(a[gap+i]<a[i]){
				temp=a[i];
				a[i]=a[gap+i];
				a[gap+i]=temp;
			}
			j=i;
			comp=a[i];
			while(j-gap>=0 && a[j-gap]>comp){
				temp=a[j-gap];
				a[j-gap]=comp;
				a[j]=temp;
				j-=gap;
			}	
			i++;
		}
	}
}
int main(){
	int i,n,arr[N];
	printf("Enter the size of array:");
	scanf("%d",&n);
	printf("Enter values:");
	for(i=0;i<n;i++) scanf("%d",&arr[i]);
	shell_sort(arr,n);
	printf("Sorted array!!\n");
	for(i=0;i<n;i++) printf("%d\t",arr[i]);
}
