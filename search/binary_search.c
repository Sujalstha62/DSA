#include<stdio.h>
#define N 30
void selection(int a[], int n){
	int i,j,temp;
	for(i=0;i<n-1;i++){
		for(j=i+1;j<n;j++){
			if(a[i]>a[j]){
				temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
		}
	}
}
void binsearch(int a[],int x,int p,int q){
	int search=p+(q-p)/2;
	if(p>q){
		printf("%d doesn't exist",x);
		return;
	} 
	if(a[search]==x){
		printf("Found at position %d",search+1);
		return;
	}
	else if(x<a[search]){
		binsearch(a,x,p,search);
	}
	else{
		binsearch(a,x,search+1,q);
	}
}
int main(){
	int i,n,find,a[N];
	printf("Enter no of terms:");
	scanf("%d",&n);
	printf("Enter values:");
	for(i=0;i<n;i++)scanf("%d",&a[i]);
	printf("Enter the no to find:");
	scanf("%d",&find);
	selection(a,n);
	printf("sorted array\n");
	for(i=0;i<n;i++)printf("%d\t",a[i]);
	printf("\n");
	binsearch(a,find,0,n-1);
}
