#include<iostream>
#include<algorithm>

#define maxSize 10001

using namespace std;

int main(){
	int n,v,i,j;
	int val[maxSize],w[maxSize],f[maxSize];

	cin>>n>>v;
	for(i = 0;i < n;i++){
		cin>>val[i]>>w[i];
	}
	memset(f,0,sizeof(f));

	for (i = 0; i < n; ++i) {
		for (j = w[i]; j <= v; ++j) {
			f[j] = max(f[j], f[j - val[i]] + w[i]);
		}
	}

	cout<<f[v]<<endl;

	system("pause");
	return 0;
}