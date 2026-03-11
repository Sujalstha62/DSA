#include<stdio.h>
#define N 30
void  insertion(int a[],int n){
	int i=1,j,temp,comp;
	while (i<n-1){
		i++;
		comp=a[i];
		j=i;
		while(j>0 && a[j-1]>comp){
			temp=a[j-1];
			a[j-1]=comp;
			a[j]=temp;
			j--;
		}
	}
}
int main(){
	int i,n,a[N];
	printf("Enter no of terms:");
	scanf("%d",&n);
	printf("Enter values:");
	for(i=0;i<n;i++)scanf("%d",&a[i]);
	insertion(a,n);
	for(i=0;i<n;i++)printf("%d\t",a[i]);
}
