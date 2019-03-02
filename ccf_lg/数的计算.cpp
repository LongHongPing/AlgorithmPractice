#include<iostream>

using namespace std;

int main(){
	int n;
	int f[1001]; 
	cin>>n;
	
	f[0] = f[1] = 1;
	for(int i = 2;i <= n;i++){
		if(i%2 == 0){
			f[i] = f[i-1]+f[i/2];
		}else{
			f[i] = f[i-1];
		}
	}
	
	cout<<f[n];
	
	return 0;
}
