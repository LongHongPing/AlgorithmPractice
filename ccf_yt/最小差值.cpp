#include<bits/stdc++.h>

using namespace std;

int main(){
	int n,ans = 100001;
	int num[1001];
	cin>>n;
	for(int i = 0;i < n;i++){
		cin>>num[i];
	}
	
	sort(num,num+n);
	for(int i = 0;i < n;i++){
		if(abs(num[i+1]-num[i]) <= ans){
			ans = abs(num[i+1]-num[i]);
			//cout<<ans<<endl;
		}
	}
	cout<<ans;
	return 0;
}
