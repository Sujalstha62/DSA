#include<stdio.h>
#define max 30
void bubble(int a[],int n){
	int i,j,temp;
	for(i=n;i>1;i--)
		for(j=0;j<i-1;j++)
			if(a[j]>a[j+1]){
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
}
int main(){
	int n,i,a[max];
	printf("Enter no of terms:");
	scanf("%d",&n);
	printf("Enter values:");
	for(i=0;i<n;i++) scanf("%d",&a[i]);
	bubble(a,n);
	for(i=0;i<n;i++) printf("%d\t",a[i]);
}
