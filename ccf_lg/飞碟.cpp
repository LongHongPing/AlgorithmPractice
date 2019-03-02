#include<iostream>
#include<string.h>

using namespace std;

int main(){
	int sum_u = 1,sum_g = 1;
	string ufo,group;
	
	cin>>ufo>>group;
	
	for(int i = 0;i < group.length();i++){
		sum_g *= group[i] - 'A'+1;
	}
	for(int i = 0;i < ufo.length();i++){
		sum_u *= ufo[i] - 'A'+1;
	}
	
	if(sum_u%47 == sum_g%47){
		cout<<"GO";
	}else{
		cout<<"STAY";
	}
	
	return 0;
	
}
