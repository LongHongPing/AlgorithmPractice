#include<iostream>

using namespace std;

int main(){
	int a[10];
	int c = 0,b;
	
	for(int i = 0;i < 10;i++){
		cin>>a[i];
	}
	cin>>b;
	
	for(int i = 0;i < 10;i++){
		if(a[i] <= b+30){
			c++;
		}
	}
	
	cout<<c;
	
	return 0; 
}
