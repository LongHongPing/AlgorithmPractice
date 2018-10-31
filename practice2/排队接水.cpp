#include<iostream>
#include<algorithm>                   //����sort������pair<>
#include<iomanip>                  //cout���������

#define maxSize 1000

using namespace std;

int main(){
	int n,i;
	double sum = 0.0;

	cin>>n;
	pair<int,int> queue[maxSize];         //pair<>��̬���飬������first��second���������ɵ���

	for(i = 0;i < n;i++){              
		cin>>queue[i].first;           //firstΪ�ȴ�ʱ��
		queue[i].second = i+1;		//secondΪ���
	}

	sort(queue,queue+n);	//Ϊʹƽ���ȴ�ʱ����С����С��������

	for(i = 0;i < n;i++){           //���㵽��n���˽�ˮʱ�ȴ�ʱ��
		sum += queue[i].first*(n-i-1);
		cout<<queue[i].second<<" ";
	}

	cout<<endl;
	cout<<fixed<<setprecision(2)<<sum/n;

	//system("pause");
	return 0;
}