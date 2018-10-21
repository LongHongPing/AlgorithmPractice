#include<iostream>

using namespace std;

//8128以后效率很低

bool isPrime(int n){
	for (int i = 2; i < sqrt(n)+1; i++){
		if (n%i == 0){
			return false;
		}
	}
	return true;
}

int main(){
	int a,b;
	int i,j,sum = 0;

	cin>>a>>b;

	for(i = a;i <= b;i++){
		if(isPrime(i)){          //素数不会是完数
			continue;
		}
		else{
			for(j = 1;j < i;j++){
				if(i % j == 0){
					sum += j;
				}
			}
			if(sum == i){
				cout<<i<<endl;
				sum = 0;
			}
			else{
				sum = 0;       //sum记得归零
			}
		}
	}

	system("pause");
	return 0;
}