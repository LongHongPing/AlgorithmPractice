#include<iostream>
#include<algorithm>

#define maxSize 10001

using namespace std;

int main(){
	int n,v,i,j;
	int vol[maxSize],val[maxSize],f[maxSize];

	memset(f,0,sizeof(f));
	cin>>n>>v;
	for(i = 0;i < n;i++){
		cin>>vol[i]>>val[i];
	}

	for(i = 0;i < n;i++){
		for(j = v;j >= vol[i];j--){
			if(f[j-vol[i]]+val[i] > f[j]){
				f[j] = f[j-vol[i]] + val[i];
			}
		}
	}

	cout<<f[v]<<endl;


	//这个ppt还是有点混乱的

	system("pause");
	return 0;
}