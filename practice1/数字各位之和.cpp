#include<iostream>

#define N 9
using namespace std;

int main(){
	int n,sum = 0;
	int num[N];
	int i,j;

	cin>>n;

	for(i = 0;n != 0;i++){
		num[i] = n%10;
		n /= 10;
	}

	for(j = 0;j < i;j++){
		sum += num[j];
	}

	cout<<sum<<endl;

	system("pause");
	return 0;
}