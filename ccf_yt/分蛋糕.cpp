#include<bits/stdc++.h>

using namespace std;

int main(){
	int n,k,ans = 0,sum = 0;
	int a[1001];
	cin>>n>>k;
	for(int i = 0;i < n;i++){
		cin>>a[i];
	}
	
	for(int i = 0;i < n;i++){
		sum += a[i];
		if(sum >= k){
			ans++;
			sum = 0;
		}
	}
	if(sum > 0 && sum < k){
		ans++;
	}
	
	cout<<ans;
	return 0;
}
