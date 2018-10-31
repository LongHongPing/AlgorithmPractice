#include<iostream>

#define maxSize 100

using namespace std;

int n;
int u[8] = {0,-1,-1,-1,0,1,1,1};
int v[8] = {1,1,0,-1,-1,-1,0,1};		//��Ӧ8������
char words[maxSize],check[maxSize][maxSize];		//Ҫ�ҵĴʣ����ʾ���
bool vis[maxSize][maxSize];			//��¼���ϵ�λ��

bool dfs(int x,int y,char w,int dir){
	if(w == 'g'){		//���һ�����ϣ���¼
		vis[x][y] = 1;
		return true;
	}

	int dx = x+u[dir],dy = y+v[dir];		//��ͬһ�������һ������
	if(dx >= 1 && dy >= 1 && dx <= n && dy <= n && check[dx][dy] == words[w]){
		if(dfs(dx,dy,words[w],dir)){
			vis[x][y] = 1;
			return true;
		}
	}

	return false;
}

int main(){
	int j,i;
	//�� yizhong
	words['y'] = 'i';
	words['i'] = 'z';
	words['z'] = 'h';
	words['h'] = 'o';
	words['o'] = 'n';
	words['n'] = 'g';

	cin>>n;
	for(i = 1;i <= n;i++){
		for(j = 1;j <= n;j++){
			cin>>check[i][j];
		}
	}

	for(i = 1;i <= n;i++){
		for(j = 1;j <= n;j++){
			if(check[i][j] == 'y'){			//�׸�����������
				for(int k = 0;k < 8;k++){		//8������
					if(dfs(i,j,'y',k)){
						vis[i][j] = 1;
					}
				}
			}
		}
	}

	//���������
	for(i = 1;i <= n;i++){
		for(j = 1;j <= n;j++){
			if(vis[i][j]){
				cout<<check[i][j];
			}
			else{
				cout<<"*";
			}
		}
		cout<<endl;
	}

	system("pause");
	return 0;
}

