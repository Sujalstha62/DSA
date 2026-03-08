#include<stdio.h>
#define N 30
int main(){
	int n,i,j,a[N],min,t;
	printf("Enter no of terms:");
	scanf("%d",&n);
	printf("Enter values:");
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	for(i=0;i<n;i++){
		min=i;
		for(j=i+1;j<n;j++){
			if(a[min]>a[j]){
				min=j;
			}
		}
		t=a[i];
		a[i]=a[min];
		a[min]=t;
	}
	for(i=0;i<n;i++){
		printf("%d\t",a[i]);
	}
}

