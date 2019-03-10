#include<bits/stdc++.h>
using namespace std;
int main(){
	int N,M;
	cin>>N>>M;
	list<int> l;
	for(int i = 1;i <= N;++i)
		l.push_back(i);
	
	while(M--){
		int a,b;
		cin>>a>>b;
		list<int>::iterator i = l.begin(); 
		while(*i != a)
			++i;
		i = l.erase(i);
		while(b<0){ 
			--i;
			++b;
		}
		while(b>0){
			++i;
			--b;
		}
		
		l.insert(i,a); 
	}
	
	for(list<int>::iterator i = l.begin();i != l.end();++i)//±éÀúÊä³ö 
		cout<<*i<<" ";
	return 0;
} 
