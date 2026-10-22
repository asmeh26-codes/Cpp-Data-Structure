#include<iostream>
using namespace std;
struct Node{
	int data;
	Node*adrs;
  Node(int value){
	data=value;
	adrs=NULL;
	}
};
class LinkedList{
	private:
		Node*head;
		Node*current;
	public:
		LinkedList(){
			head=NULL;
		}
 // ADD NODE AT END FUNCTION:
void add_NodeE(int value){
	Node*newNode=new Node(value);
	if(head==NULL){
		head=newNode;
		return;
	}
	current=head;
	while(current->adrs!=NULL){
		current=current->adrs;
	}
		current->adrs=newNode;
		current=newNode;
		}
	// ADD NODE AT START FUNCTION:
void add_NodeS(int value){
	Node*newNode=new Node(value);
	if(head==NULL){
		head=newNode;
		return;
	}
	newNode->adrs=head;
	head=newNode;
	current=newNode;
}
  // ADD NODE AT IN_BETWEEN FUNCTION:
void add_NodeInBetween(int findvalue,int newvalue){
	if(head==NULL){
		cout<<"List is empty"<<endl;
	   return;
	}
	current=head;
	while(current!=NULL&&current->data!=findvalue){
		current=current->adrs;
	}
	if(current!=NULL){
		Node*newNode=new Node(newvalue);
		newNode->adrs=current->adrs;
		current->adrs=newNode;
		cout<<"New node added after: "<<findvalue<<endl;
		return;
	}
	cout<<"value: "<<findvalue<<"not found in the list"<<endl;

}
   // DISPLAY FUNCTION:
void display(){
	if (head==NULL){
		cout<<"List is Empty"<<endl;
		return;
	}
	current=head;
	while(current!=NULL){
		cout<<current->data<<" "<<endl;
		current=current->adrs;
	}
	cout<<"\n"<<endl;
}
   // SEARCH FUNCTION:
void search_Node(int s_value){
	if (head==NULL){
		cout<<"List is Empty"<<endl;
		return;
	}
	current=head;
	while(current!=NULL){
		if(current->data==s_value){
			cout<<"Searching Node is found"<<endl;
			cout<<"value"<<current->data<<"is found"<<endl;
			return;
		}
				current=current->adrs;
			}
			cout<<"Node not found"<<endl;
		}
	// DELETE HEAD FUNCTION:
void del_head(){
	if (head==NULL){
		cout<<"List is Empty"<<endl;
		return;
	}
	current=head;
	head=head->adrs;
	delete current;
	cout<<"Head Node deleted!"<<endl;
}
  // DELETE IN_BETWEEN NODE FUNCTION:
void del_Node(int del_value){
	if (head==NULL){
		cout<<"List is Empty"<<endl;
		return;
	}
	current=head;
	while(current->adrs!=NULL){
		if(current->adrs->data==del_value){
			Node*temp=current->adrs;
			current->adrs=temp->adrs;
			delete temp;
			cout<<"Node deleted"<<endl;
			return;
		}
		current=current->adrs;
	}
	cout<<"Node value is not found!"<<endl;
}
  // DELETE END NODE FUNCTION:
void deleteEnd(){
	if(head==NULL){
		cout<<"List is empty"<<endl;
		return;
	}
	if(head->adrs==NULL){
		delete head;
		head=NULL;
		return;
	}
	current=head;
	while(current->adrs->adrs!=NULL){
		current=current->adrs;
	}
	Node*temp=current->adrs;
	current->adrs=NULL;
	delete temp;
	cout<<"End node deleted"<<endl;
}
};
   // MAIN FUNCTION:
int main(){
	LinkedList list;
	int s_value;
	int del_value;
	list.add_NodeE(20);
	list.add_NodeE(60);
	list.add_NodeS(10);
	list.add_NodeE(80);
	list.display();
	list.add_NodeInBetween(60,50);
	list.display();
	list.add_NodeInBetween(20,30);
	list.display();
	cout<<"Enter searching value: "<<endl;
	cin>>s_value;
	list.search_Node(s_value);
	list.display();
	list.del_head();
	list.display();
	cout<<"Enter deleting value:"<<endl;
	cin>>del_value;
	list.del_Node(del_value);
	list.deleteEnd();
	list.display();
	return 0;
}
