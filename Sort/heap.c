#include<stdio.h>
#define N 100
void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
void heapify(int arr[],int n,int i){
    int largest=i;
    int left=2*i+1;
    int right=2*i+2;
    if(left<n && arr[left]>arr[largest])
		largest=left;
    if(right<n && arr[right]>arr[largest])
    	largest = right;
    if(largest!=i){
    	swap(&arr[i],&arr[largest]);
    	heapify(arr,n,largest);
    }
}
void heapSort(int arr[],int n){
	int i;
    for(i=n/2-1;i>=0;i--)
        heapify(arr,n,i);
    for(i=n-1;i>=0;i--){
        swap(&arr[0],&arr[i]);
        heapify(arr,i,0);
    }
}
int main(){
	int n,i,a[N];
	printf("Enter no of terms:");
	scanf("%d",&n);
	printf("Enter values:");
	for(i=0;i<n;i++) scanf("%d",&a[i]);
	heapSort(a,n);
	for(i=0;i<n;i++) printf("%d\t",a[i]);
	printf("\n");
}
