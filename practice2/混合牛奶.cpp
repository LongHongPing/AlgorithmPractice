#include<iostream>
#include<algorithm>

#define maxSize 20000					//不能太大，不然动态数组会冲突

using namespace std;

int main(){
	int n,m,i;
	pair<int,int> milk[maxSize];
	
	cin>>n>>m;

	for(i = 0;i < m;i++){           //first是需要牛奶总量，second是提供牛奶户人数
		cin>>milk[i].first>>milk[i].second;
	}

	sort(milk,milk+m);

	int price = 0,sum = 0;
	//贪心算法，部分
	for(i = 0;i < m;i++){
		if(sum + milk[i].second <= n){           //牛奶户提供牛奶量不超过需求时
			price += milk[i].first*milk[i].second;
			sum += milk[i].second;
		}
		else{
			price += milk[i].first*(n-sum);
			break;
		}
	}
	
	cout<<price<<endl;		//花费最少

	system("pause");
	return 0;
}