#include<bits/stdc++.h>

using namespace std;

int main(){
	int n,k;
	queue<int> q;
	cin>>n>>k;
	for(int i = 1;i <= n;i++){
		q.push(i);
	}
	
	int num = 1;
	while(q.size() > 1){
		int t = q.front();
		q.pop();
		if(!(num%10 == k || num%k == 0)){
			q.push(t);
		}
		num++;
	}
	cout<<q.front();
	return 0;
}
