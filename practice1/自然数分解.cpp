#include<iostream>
#include<math.h>

using namespace std;

int main(){
	int n,result;
	int cube,sum = 0;

	cin>>n;
	cube = pow(n,3);


	//第一个奇数a = n^2 - n+1;
	result = n*n-n+1;
	cout<<result<<" ";
	for(int j=1; j < n;j++){
		result += 2;
		cout<<result<<" ";
	}

	system("pause");
	return 0;
}