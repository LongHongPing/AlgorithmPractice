#include<iostream>
#include<algorithm>

#define maxSize 20000					//����̫�󣬲�Ȼ��̬������ͻ

using namespace std;

int main(){
	int n,m,i;
	pair<int,int> milk[maxSize];
	
	cin>>n>>m;

	for(i = 0;i < m;i++){           //first����Ҫţ��������second���ṩţ�̻�����
		cin>>milk[i].first>>milk[i].second;
	}

	sort(milk,milk+m);

	int price = 0,sum = 0;
	//̰���㷨������
	for(i = 0;i < m;i++){
		if(sum + milk[i].second <= n){           //ţ�̻��ṩţ��������������ʱ
			price += milk[i].first*milk[i].second;
			sum += milk[i].second;
		}
		else{
			price += milk[i].first*(n-sum);
			break;
		}
	}
	
	cout<<price<<endl;		//��������

	system("pause");
	return 0;
}