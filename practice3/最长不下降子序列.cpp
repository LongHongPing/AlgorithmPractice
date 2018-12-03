#include<iostream>
#include<algorithm>

#define maxSize 20

using namespace std;

int m;
int b[maxSize],f[maxSize];

int calc(int n){
	f[1] = b[1];
	int len = 0;

	for(int i = 1;i < n;i++){
		if(b[i] >= f[len]){
			f[++len] = b[i];
		}
		else{
			int j = upper_bound(f+1,f+len+1,b[i])-f;
			f[j] = b[i];
		}
	}

	return len;
}

int main(){	
	cin>>m;
	for(int i = 0;i < m;i++){
		cin>>b[i];
	}

	cout<<calc(m);
	system("pause");
	return 0;
}