#include<iostream>

#define maxSize 100

using namespace std;

int isPrime(int n){
	for(int i = 2;i <= sqrt(n)+1;i++){
		if(n%i == 0){
			return 0;
		}
	}
	return 1;
}

int main(){
	int m,i,j,temp;
	int num[maxSize],result_a[maxSize],result_b[maxSize];

	cin>>m;

	for(i = 0;i < m;i++){
		cin>>num[i];
	}

	for(i = 0;i < m;i++){
		for(j = 2;;j++){
			if(isPrime(j)){
				temp = num[i]-j;
				if(isPrime(temp)){
					result_a[i] = j;
					result_b[i] = temp;
					break;
				}
			}
		}
	}

	for(i = 0;i < m;i++){
		cout<<result_a[i]<<" "<<result_b[i]<<endl;
	}

	system("pause");
	return 0;
}