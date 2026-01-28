#include<iostream>
#include<cctype>
using namespace std;
int gcd(int a,int b){
	if(b==0){
		return a;
	}
	return gcd(b,a%b);
}
int main(){
	int a,b;
	while(true){
		cout<<"Enter two numbers:";
		cin>>a>>b;
		if(!cin.fail())
			cout<<"GCD="<<gcd(a,b)<<endl;
		else{
			cout<<"Porgram terminated...";
			return 0;
		}
	}
	
}
