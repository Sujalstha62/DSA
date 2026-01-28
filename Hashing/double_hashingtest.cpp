#include<iostream>
#include<vector>
#include<cctype>
bool fact(int x){
	for(int i=2;i<x;i++){
		if(x%i==0){
			return false;
		}
	}
	return true;
}
using namespace std;
int main(){
	int n,i,hash,count=0,hash_key,hash_ke,pf;
	cout<<"Enter the number of available location:";
	cin>>n;
	vector<int> arr(n,-1);
	while(count<n){
		cout<<"Enter number:";
		cin>>hash;
		if(cin.fail()){
			break;
		}
		hash_key=hash%n;
		if(arr[hash_key]==-1){
			arr[hash_key]=hash;
		}
		else{
			for(i=n-1;i>=1;i--){
				if(fact(i)){
					pf=i;
					break;
				}
			}
			i=1;
			hash_ke=hash_key;
			while(arr[hash_ke]!=-1){
				hash_ke=(hash_key+i*(pf-(hash%pf)))%n;
				i++;
			}
			arr[hash_ke]=hash;
			}
		count++;
		}
	cout<<endl;
	for(i=0;i<n;i++){
		cout<<arr[i]<<"\t";
	}
}
