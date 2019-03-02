#include<iostream>
#include<math.h>

using namespace std;

bool isPrime(int n){
	if(n == 2) return true;
	if(n%2 == 0) return false;
	
	int x = sqrt(n)+1;
	for(int i = 2;i < x;i++){
		if(n%i == 0) return false;
	}
	return true;
}

int main(){
	int n;
	cin>>n;
	
	for(int i = 2;i < n;i++){
		for(int j = 2;j < n;j++){
			int k = n-i-j;
			if(isPrime(i) && isPrime(j) && isPrime(k)){
				cout<<i<<" "<<j<<" "<<k;
				return 0;
			}
		}
	}
	return 0;
} 
