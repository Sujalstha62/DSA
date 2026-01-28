 #include<iostream>
using namespace std;
#define N 2
class linqueue{
	int top,bottom;
	int arr[N];
	public:
		linqueue(){
			top=bottom=-1;
		}
		void inqueue(int n){
			if(top==N-1){
				cout<<"Queue full!!"<<endl;
				return;
			}
			arr[++top]=n;
		}
		int dequeue(){
			if(top==-1 || top<=bottom){
				cout<<"Queue Empty!!"<<endl;
				return 0;
			}
			return arr[++bottom];
		}
		bool empty(){
			if(top==-1 || top==bottom)return true;
			else return false;
		}
		bool full(){
			if(top==N-1)return true;
			else return false;
		}
};
int main(){
	linqueue A;
	int ch,x;
	cout<<"Choose opertaion:"<<endl;
	while(true){
	cout<<endl<<"1.Inqueue\n2.Dequeue\n3.Check if Queue empty\n4.Check if Queue full\nEnter your choice:";
	cin>>ch;
		switch(ch){
		case 1:
			cout<<"Enter a number:";
			cin>>x;
			A.inqueue(x);
			break;
		case 2:
			cout<<A.dequeue()<<" Dequeued"<<endl;
			break;
		case 3:
			if(A.empty())cout<<"Queue empty!!\n";
			else cout<<"Queue not empty\n";
			break;
		case 4:
			if(A.full()) cout<<"Queue full!!\n";
			else cout<<"Queue not full!!\n";
			break;
		default:
			cout<<"Invalid input program termintatd!!";
			return 0;
		}
	}
}
