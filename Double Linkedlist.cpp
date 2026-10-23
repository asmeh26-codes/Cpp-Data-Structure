#include<iostream>
using namespace std;
struct Node{
	int data;
	Node*adrs_P;
	Node*adrs_N;
	Node(int value){
		data=value;
		adrs_P=NULL;
		adrs_N=NULL;
	}
};
class DoubleLinkedList{
	private:
		Node*head;
		Node*current;
	public:
		DoubleLinkedList(){
			head=NULL;
		}
		//ADD NODE AT END:
void add_NodeEnd(int value){
	Node*newNode=new Node(value);
	if(head==NULL){
		head=newNode;
		return;
	}
	current=head;
	while(current->adrs_N!=NULL){
		current=current->adrs_N;
	}
	current->adrs_N=newNode;
	newNode->adrs_P=current;
}
  //ADD NODE AT START:
void add_NodeS(int value){
	Node*newNode=new Node(value);
	if(head==NULL){
		head=newNode;
		return;
	}
	newNode->adrs_N=head;
	head->adrs_P=newNode;
	head=newNode;
}
   //ADD NODE IN BETWEEN:
void add_NodeInBetween(int findvalue,int newvalue){
	if(head==NULL){
		cout<<"List is empty"<<endl;
	   return;
	}
	current=head;
	while(current!=NULL&&current->data!=findvalue){
		current=current->adrs_N;
	}
	if(current!=NULL){
		Node*newNode=new Node(newvalue);
		newNode->adrs_N = current->adrs_N;
        newNode->adrs_P = current;
    if(current->adrs_N != NULL){
        current->adrs_N->adrs_P =newNode;
}
        current->adrs_N = newNode;
		cout<<"New node added after: "<<findvalue<<endl;
		return;
	}
  cout<<"value: "<<findvalue<<"not found in the list"<<endl;
}
    //DELETE HEAD FUNCTION:
void del_head(){
	if (head==NULL){
		cout<<"List is Empty"<<endl;
		return;
	}
	Node*deleteNode=head;
	head=head->adrs_N;
	
	if(head!=NULL){
		head->adrs_P=NULL;
	}
	delete deleteNode;
	cout<<"Head Node deleted!"<<endl;
}
    //DELETE END NODE:
void deleteEnd(){
	if(head==NULL){
		cout<<"List is empty"<<endl;
		return;
	}
	current=head;
	if(current->adrs_N==NULL){
		delete current;
		head=NULL;
		cout<<"End node deleted"<<endl;
		return;
	}
	while(current->adrs_N!=NULL){
		current=current->adrs_N;
	}
		current->adrs_P->adrs_N=NULL;
	delete current;
	cout<<"End node deleted"<<endl;
}
  // DELETE IN BETWEEN NODE:
void del_Node(int del_value){
	if (head==NULL){
		cout<<"List is Empty"<<endl;
		return;
	}
	current=head;
	while(current!=NULL){
		if(current->data==del_value){
			Node*deleteNode=current;
			deleteNode->adrs_P->adrs_N=deleteNode->adrs_N;
			if(deleteNode->adrs_N!=NULL){
				deleteNode->adrs_N->adrs_P=deleteNode->adrs_P;
			}
			delete deleteNode;
			cout<<"Node deleted!"<<endl;
			return;
		}
		current=current->adrs_N;
	}
	cout<<"Node not found!"<<endl;

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
				current=current->adrs_N;
			}
			cout<<"Node not found"<<endl;
		}
		//DISPLAY FUNCTION:
void display(){
	if (head==NULL){
		cout<<"List is empty"<<endl;
		return;
	}
	current=head;
	while(current!=NULL){
		cout<<current->data<<" ";
		current=current->adrs_N;
	}
	cout<<"\n"<<endl;
}
   // REVERSE SHOW LIST:
void showreverse_list(){
	if (head==NULL){
		cout<<"List is empty"<<endl;
		return;
	}
	current=head;
	while(current->adrs_N!=NULL){
		current=current->adrs_N;
	}
	while(current!=NULL){
		cout<<current->data<<" "<<endl;
		current=current->adrs_P;
	}
	cout<<" \n "<<endl;
}
};
  //MAIN FUNCTION:
int main(){
	DoubleLinkedList dll;
	int s_value;
	int del_value;
	dll.add_NodeS(10);
	dll.add_NodeEnd(55);
	dll.add_NodeS(20);
	dll.add_NodeEnd(50);
    dll.add_NodeInBetween(50,70);
	dll.display();
	cout<<"Enter searching value: "<<endl;
	cin>>s_value;
	dll.search_Node(s_value);
	dll.del_head();
	dll.display();
	dll.deleteEnd();
	dll.display();
	cout<<"Enter deleting value:"<<endl;
	cin>>del_value;
	dll.del_Node(del_value);
	dll.display();
	dll.showreverse_list();
	return 0;
}
