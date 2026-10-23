#include<iostream>
using namespace std;
int main(){
	int arr[7]={3,4,6,2,1,8,5};
	cout<<"Values Before Sorting:"<<endl;
	for(int i=0;i<7;i++){
		cout<<" "<<arr[i]<<" ";
	}
	cout<<endl;
for(int p=0;p<7;p++){
	for(int c=0;c<7;c++){
		if(arr[c]>arr[c+1]){
			int temp;
			temp=arr[c];
			arr[c]=arr[c+1];
			arr[c+1]=temp;
		}
	}
}
cout<<"Values After Sorting:"<<endl;
for(int i=0;i<7;i++){
	cout<<arr[i]<<" ";
}
	return 0;
}