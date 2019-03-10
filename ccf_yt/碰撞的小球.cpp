#include<bits/stdc++.h>

using namespace std;

int main(){
	int n,l,t;
	int posit[1001];
	pair<int,int> ball[101];
	cin>>n>>l>>t;
	memset(posit,0,sizeof(posit));//当前位置是否有球 
	
	for(int i = 1;i <= n;i++){
		ball[i].first = 1;//球方向 
		cin>>ball[i].second;//球位置 
		posit[ball[i].second] = i;
	}
	
	while(t--){
		for(int i = 1;i <= n;i++){
			posit[ball[i].second] = 0;		//移走球 
			ball[i].second += ball[i].first;
			if(posit[ball[i].second] != 0){//有球 
				ball[i].first = -ball[i].first;
				ball[posit[ball[i].second]].first = -ball[posit[ball[i].second]].first; 
			}else if(ball[i].second == 0 || ball[i].second ==l){//边界
				ball[i].first = -ball[i].first;
			}
			posit[ball[i].second] = i;//移入球 
		} 
	}
	
	for(int i = 1;i <= n;i++){
		cout<<ball[i].second<<" ";
	}
	return 0;
} 
