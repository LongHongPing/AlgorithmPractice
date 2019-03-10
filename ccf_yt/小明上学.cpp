#include<iostream>

using namespace std;

int main(){
	int r,y,g,n,sum = 0;
	int k[101],t[101];
	cin>>r>>y>>g;
	cin>>n;
	for(int i = 0;i < n;i++){
		cin>>k[i]>>t[i];
	}
	
	for(int i = 0;i < n;i++){
		if(k[i] == 0){
			sum += t[i];
		}else if(k[i] == 1){
			sum += t[i];
		}else if(k[i] == 2){
			sum = sum+t[i]+r;
		}else{
			continue;
		}
	}
	cout<<sum;
	return 0;
}
