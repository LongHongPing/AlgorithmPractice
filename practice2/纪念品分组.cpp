#include<iostream>
#include<algorithm>

#define maxSize 30000

using namespace std;

int main(){
	int w,n,i,j;
	int p[maxSize];
	int count = 0;

	cin>>w;		//ÿ������۸�����
	cin>>n;		//������
	for(i = 0;i < n;i++){
		cin>>p[i];		//ÿ������۸�
	}

	sort(p,p+n);

	//������������˵���������
	for(i = 0,j = n-1;i <= j;){
		if(p[i] + p[j] <= w){		//ÿ�������������
			count++;
			i++;j--;
		}
		else{		//�������������һ������Ϊһ��
			count++;
			j--;
		}
	}

	cout<<count<<endl;

	system("pause");
	return 0;
}