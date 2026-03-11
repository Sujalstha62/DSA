#include <stdio.h>
#define MAX 20
int main(){
    int n,i,hash,count=0,hash_key,hash_ke;
    int arr[MAX];
    for(i=0;i<MAX;i++) arr[i]=-1;
    printf("Enter the number of available locations:");
    scanf("%d",&n);
    printf("Enter numbers: ");
    while(count<n){
        if(!scanf("%d",&hash)) break;
        hash_ke=hash%n;
        hash_key=hash_ke;
        i=1;
        while(arr[hash_key]!=-1){
            hash_key=(hash_ke+(i*i))%n; 
            i++;
        }
        arr[hash_key]=hash;
        count++;
    }
    printf("\nFinal Hash Table:\n");
    for(i=0;i<n;i++) printf("%d\t",arr[i]);
    printf("\n");
    return 0;
}
