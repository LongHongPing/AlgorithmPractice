#include<iostream>
#include<algorithm>

#define maxCon 20001
#define maxPro 301

using namespace std;

int main(){
	int v,n,i;
	int weight[maxPro],f[maxCon];

	cin>>v>>n;
	for(i = 0;i < n;i++){
		cin>>weight[i];
	}

	memset(f,0,sizeof(f));

	for(i = 0;i < n;i++){
		for(int j = v;j >= weight[i];j-- ){
			f[j] = max(f[j],f[j-weight[i]]+weight[i]);
		}
	}

	cout<<v-f[v]<<endl;

	system("pause");
	return 0;
}