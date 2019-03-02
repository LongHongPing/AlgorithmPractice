#include<iostream>

using namespace std;

int main(){
	int c;
	long a[100];
	
	for(int i = 0; ;i++){
		cin>>a[i];
		if(a[i] == 0){
			c = i-1;
			break;
		}
	}
	
	for(int i = c;i >= 0;i--){
		cout<<a[i]<<" ";
	}
	
	return 0; 
}
