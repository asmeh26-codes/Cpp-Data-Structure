#include<iostream>
using namespace std;
class Linear_StudentQueue{
private:
	int arr[5];
	int rear;
	int front;
public:
	Linear_StudentQueue(){
	 front=-1;
	 rear=-1;
	}
void EnqueueStu(int ID){
	if(rear==4){
		cout<<"Queue  is overflow!No space available at the rear"<<endl;
		return;
	}
	if(front==-1){
		front=0;
	}
    	rear++;
	arr[rear]=ID;
	cout<<ID<<" inserted"<<endl;
}
void DequeueStu(){
	if(front==-1){
	  cout<<"Queue underflow!No students to serve"<<endl;
    return;
}
cout<<"Deleted value:"<<arr[front]<<endl;
if(front>rear){
	front=-1;
	rear=-1;
}
else{
	front++;
}
}
void displayStu(){
	if(front==-1){
		cout<<"Queue is empty"<<endl;
		return;
	}
	cout<<"Student Queue IDs:"<<endl;
	for(int i=front;i<=rear;i++){
		cout<<arr[i]<<endl;
	}
}
};
int main(){
   Linear_StudentQueue lsq;
   lsq.EnqueueStu(101);
   lsq.EnqueueStu(102);
   lsq.EnqueueStu(103);
   lsq.EnqueueStu(104);
   lsq.EnqueueStu(105);
   lsq.displayStu();
   lsq.DequeueStu();
   lsq.DequeueStu();
    lsq.displayStu();
   lsq.EnqueueStu(106);
   lsq.displayStu();
	return 0;
}
