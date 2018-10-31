#include<iostream>
#include<algorithm>

#define maxSize 30000

using namespace std;

int main(){
	int w,n,i,j;
	int p[maxSize];
	int count = 0;

	cin>>w;		//每组礼物价格上限
	cin>>n;		//礼物数
	for(i = 0;i < n;i++){
		cin>>p[i];		//每个礼物价格
	}

	sort(p,p+n);

	//测试最贵和最便宜的两个礼物
	for(i = 0,j = n-1;i <= j;){
		if(p[i] + p[j] <= w){		//每组最多两个礼物
			count++;
			i++;j--;
		}
		else{		//不能两个，则后一个单独为一组
			count++;
			j--;
		}
	}

	cout<<count<<endl;

	system("pause");
	return 0;
}