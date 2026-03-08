#include<stdio.h>
#define N 30
int main(){
	int i,n,find,a[N];
	printf("Enter no of terms:");
	scanf("%d",&n);
	printf("Enter values:");
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	printf("Enter the no to find:");
	scanf("%d",&find);
	for(i=0;i<n;i++){
		if(a[i]==find){
			printf("Found at position %d\n",i+1);
			break;
		}
	if(i==n-1){
		printf("%d doesn't exist",find);
	}
	}
}
