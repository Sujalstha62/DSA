#include<iostream>
using namespace std;
#define N 3
class cirqueue{
	int top,bottom;
	int arr[N];
	public:
		cirqueue(){
			top=bottom=-1;
		}
		void enqueue(int n){
			if(top==N-1 && bottom==-1){
				cout<<"Queue full!!\n";
				return;
			}
			if(top-bottom<N){
				top++;
				arr[top%N]=n;	
			}
			else cout<<"Queue full!!\n";
		}
		int dequeue(){
			if(top==bottom){
				cout<<"Queue Empty!!\n";
				return 0;
			}
			bottom++;
			return arr[bottom%N];
		}
		bool empty(){
			if(top==bottom || top==-1) return true;
			else return false;
		}
		bool full(){
			if((top==N-1 && bottom==-1) || top-bottom==N)return true;
			return false;
		}
};
int main(){
	cirqueue A;
	int ch,x;
	cout<<"Choose opertaion:"<<endl;
	while(true){
	cout<<endl<<"1.Enqueue\n2.Dequeue\n3.Check if queue empty\n4.Check if queue full\nEnter your choice:";
	cin>>ch;
		switch(ch){
		case 1:
			cout<<"Enter a number:";
			cin>>x;
			A.enqueue(x);
			break;
		case 2:
			cout<<A.dequeue()<<" Dequeued"<<endl;
			break;
		case 3:
			if(!A.empty())cout<<"Queue not empty!!\n";
			else cout<<"Queue empty!!\n";
			break;
		case 4:
			if(A.full())cout<<"Queue full!!\n";
			else cout<<"Queue not full!!\n";
			break;
		default:
			cout<<"Invalid input program termintatd!!";
			return 0;
		}
	}
}
