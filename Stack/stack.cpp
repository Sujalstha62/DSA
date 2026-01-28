#include <iostream>
#include <conio.h>
using namespace std;
#define max 5
class Stac {
    int st[max];
    int top;
public:
	Stac(){
		top=-1;
	}
    void push(int value) {
        if (top == max - 1) 
        cout << "Stack Overflow!\n";
        else {
            st[++top] = value;
            cout << value << " pushed.\n";
        }
    }
    void pop() {
        if (top == -1)
        cout << "Stack Underflow!\n";
        else {
            cout << st[top] << " popped.\n";
            top--;
        }
    }
    void peek() {
        if (top == -1)
            cout << "Stack is empty!\n";
        else {
            cout << "Top element: " << st[top] << endl;
        }
    }
    void show() {
        if (top==-1){
            cout << "Stack is empty!\n";
            return;
        }
        for(int i=top;i>=0;i--){
        	cout<<st[i]<<"\n";
		}
    }
};
int main() {
    Stac A;
    int value,ch;
    while(true){
    	cout<<"1.Push\n2.Pop\n3.Peek\n4.Show\n"
    	<<"Enter your choice:";
    cin>>ch;
    	switch(ch){
    	case 1:
    		cout<<"Enter value:";
    		cin>>value;
    		A.push(value);
    		break;
    	case 2:
    		A.pop();
    		break;
    	case 3:
    		A.peek();
    		break;
    	case 4:
    		A.show();
    		break;
    	default:
    		return 0;
    }
	}
}

