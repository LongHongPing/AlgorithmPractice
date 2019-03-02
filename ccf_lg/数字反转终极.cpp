#include<iostream>

using namespace std;

int main(){
	int n,i,j,k;
	int x[11];
	cin>>n;
	
	if(n == 0){
		cout<<"0";
		return 0;
	}
	
	if(n < 0){
		cout<<"-";
		n = -1*n;
	}
	
	for(i = 0;n != 0;i++){
		x[i] = n%10;
		n /= 10;
	}	
	k = i;
	i = 0; 
	while(x[i] == 0) i++;
	for(j = i;j < k;j++){
		cout<<x[j];
	}
	return 0;
	
} 
