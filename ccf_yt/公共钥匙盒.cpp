#include<bits/stdc++.h>

using namespace std;

struct key{
	int num;
	int time;
	bool status;
	
	key(int n,int t,bool s):num(n),time(t),status(s){
	}
	bool operator<(const key&k)const{
		if(this->time != k.time){
			return this->time > k.time;
		}else if(this->status != k.status){
			return this->status && !k.status;
		}else{
			return this->num > k.num;
		}
	}
};

int main(){
	int n,k,w,s,c;
	int a[10001];
	cin>>n>>k;
	priority_queue<key> pq_key;
	
	for(int i = 1;i <= n;i++){
		a[i] = i; 
	}
	
	for(int i = 0;i < k;i++){
		cin>>w>>s>>c;
		pq_key.push(key(w,s,true));
		pq_key.push(key(w,s+c,false));
	}
	while(!pq_key.empty()){
		key temp = pq_key.top();
		pq_key.pop();
		if(temp.status){		//È¡Ô¿³× 
			int i = 1;
			while(a[i] != temp.num){
				++i;
			}
			a[i] = -1;
		}else{
			int i = 1;
			while(a[i] != -1){
				++i;
			}
			a[i] = temp.num;
		} 
	}
	for(int i = 1;i <= n;i++){
		cout<<a[i]<<" ";
	}
	return 0;
}
