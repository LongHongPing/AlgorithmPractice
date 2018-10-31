#include<iostream>

#define maxSize 100

using namespace std;

int n;
int u[8] = {0,-1,-1,-1,0,1,1,1};
int v[8] = {1,1,0,-1,-1,-1,0,1};		//对应8个方向
char words[maxSize],check[maxSize][maxSize];		//要找的词，单词矩阵
bool vis[maxSize][maxSize];			//记录符合的位置

bool dfs(int x,int y,char w,int dir){
	if(w == 'g'){		//最后一个符合，记录
		vis[x][y] = 1;
		return true;
	}

	int dx = x+u[dir],dy = y+v[dir];		//向同一方向的下一个搜索
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
	//串 yizhong
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
			if(check[i][j] == 'y'){			//首个符合则搜索
				for(int k = 0;k < 8;k++){		//8个方向
					if(dfs(i,j,'y',k)){
						vis[i][j] = 1;
					}
				}
			}
		}
	}

	//按规则输出
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

