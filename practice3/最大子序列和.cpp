#include<iostream>

#define maxSize 100

using namespace std;

int n;
int a[maxSize],f[maxSize];

int main(){
	int i,max = 0;
	cin>>n;
	for(i = 0;i < n;i++){
		cin>>a[i];
	}

	f[0] = a[0];
	for(i = 1;i < n;i++){
		if(f[i - 1] > 0){
			f[i] = f[i-1]+a[i];
		}
		else{
			f[i] = a[i];
		}

		if(f[i] > max){
			max = f[i];
		}
	}

	cout<<max;
	system("pause");
	return 0;
}