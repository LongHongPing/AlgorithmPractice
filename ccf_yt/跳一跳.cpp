#include<bits/stdc++.h>

using namespace std;

int main(){
	int n,num = 1,sum = 0;
	
	while(1){
		cin>>n;
		if(n == 0){
			break;
		}else if(n == 1){
			num = 1;
			sum += 1;
		}else if(n == 2){
			sum += (2*num);
			num++;
		}
	}
	cout<<sum;
	return 0;
} 
