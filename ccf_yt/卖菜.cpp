#include<iostream>

using namespace std;

int main(){
	int n;
	int price_a[1001],price_b[1001];
	cin>>n;
	for(int i = 1;i <= n;i++){
		cin>>price_a[i];
	}
	
	for(int i = 1;i <= n;i++){
		if(i == 1){
			price_b[i] = (price_a[i]+price_a[i+1])/2;
		}else if(i == n){
			price_b[i] = (price_a[i]+price_a[i-1])/2;
		}else{
			price_b[i] = (price_a[i]+price_a[i+1]+price_a[i-1])/3;	
		}
		cout<<price_b[i]<<" ";
	}
	return 0;
} 
