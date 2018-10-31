#include<iostream>
#include<algorithm>                   //调用sort（），pair<>
#include<iomanip>                  //cout输出浮点数

#define maxSize 1000

using namespace std;

int main(){
	int n,i;
	double sum = 0.0;

	cin>>n;
	pair<int,int> queue[maxSize];         //pair<>动态数组，里面有first和second两个参数可调用

	for(i = 0;i < n;i++){              
		cin>>queue[i].first;           //first为等待时间
		queue[i].second = i+1;		//second为序号
	}

	sort(queue,queue+n);	//为使平均等待时间最小，从小到大排序

	for(i = 0;i < n;i++){           //计算到第n个人接水时等待时间
		sum += queue[i].first*(n-i-1);
		cout<<queue[i].second<<" ";
	}

	cout<<endl;
	cout<<fixed<<setprecision(2)<<sum/n;

	//system("pause");
	return 0;
}