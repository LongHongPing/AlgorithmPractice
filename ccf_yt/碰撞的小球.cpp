#include<bits/stdc++.h>

using namespace std;

int main(){
	int n,l,t;
	int posit[1001];
	pair<int,int> ball[101];
	cin>>n>>l>>t;
	memset(posit,0,sizeof(posit));//��ǰλ���Ƿ����� 
	
	for(int i = 1;i <= n;i++){
		ball[i].first = 1;//���� 
		cin>>ball[i].second;//��λ�� 
		posit[ball[i].second] = i;
	}
	
	while(t--){
		for(int i = 1;i <= n;i++){
			posit[ball[i].second] = 0;		//������ 
			ball[i].second += ball[i].first;
			if(posit[ball[i].second] != 0){//���� 
				ball[i].first = -ball[i].first;
				ball[posit[ball[i].second]].first = -ball[posit[ball[i].second]].first; 
			}else if(ball[i].second == 0 || ball[i].second ==l){//�߽�
				ball[i].first = -ball[i].first;
			}
			posit[ball[i].second] = i;//������ 
		} 
	}
	
	for(int i = 1;i <= n;i++){
		cout<<ball[i].second<<" ";
	}
	return 0;
} 
