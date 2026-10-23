#include<iostream>
using namespace std;
class stack{
private:
	int BSAI[5];
	int top;
public:
	stack(){
	 top=-1;
	}
void push(int value){
	if(top==4){
		cout<<"Stack is overflow"<<endl;
		return;
	}
	top++;
	BSAI[top]=value;
	}
void pop(int value){
	if(top==-1){
		cout<<"Stack is underflow"<<endl;
		return;
	}
	BSAI[top]=0;
	top--;
}
void display(){
	if(top==-1){
		cout<<"Stack is empty"<<endl;
		return;
	}
	for(int x=top;x>=0;top--){
		cout<<BSAI[x]<<endl;
	}
}
};
int main(){
	stack stk;
	stk.push(27);
	stk.push(10);
	stk.display();
	return 0;
}
