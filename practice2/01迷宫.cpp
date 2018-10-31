#include<iostream>
#include<cstring>

#define maxSize 1000001
#define size 1001

using namespace std;

int father[maxSize],child[maxSize];		//fa为根，ch为子节点
int n;

int u[4] = {1,-1,0,0};
int v[4] = {0,0,1,-1};		//四个方向

char s[size][size];		//存迷宫

//查
int find(int x){
	return father[x] == x ? x : father[x] = find(father[x]);
}

//并
void union_(int x,int y){
    int r1 = find(x),r2 = find(y);
	if(r1 != r2){		//设r1为根，r2的值替换为r1的下标，将r1,r2合并
		child[r1] += child[r2],father[r2] = father[r1];
	}
}


//构造点到节点一一映射：(i,j)=i*n+j;
int dfs(int x,int y){
	if(father[x*n+y] != -1){
		return find(x*n+y);
	}

    father[x*n+y] = x*n+y,child[x*n+y] = 1;		//构造映射
    
	for(int k = 0;k < 4;k++){
        int dx = x+u[k],dy = y+v[k];
		if(dx >= 0 && dx < n && dy >= 0 && dy < n && s[x][y] != s[dx][dy]){
			union_(x*n+y,dfs(dx,dy));
		}	
    }
    return find(x*n+y);
}

int main(){
    int m;  
    cin>>n>>m;			//下面n行，每行n个字符，字符只可能是0或者1，字符之间没有空格。
						//接下来m行，每行2个用空格分隔的正整数i,j对应了迷宫中第i行第j列的一个格子
						//询问从这一格开始能移动到多少格。

    memset(father,-1,4*n*n); 		//初始化集合，负数为根
    
	for(int i = 0;i < n;i++)
		cin>>s[i];

    int i[size],j[size];
    
	for(int k = 0;k < m;k++){
		cin>>i[k]>>j[k];		//起始位置
	}

	for(int k = 0;k < m;k++){
        cout<<child[dfs(i[k]-1,j[k]-1)]<<endl;
    }

	system("pause");
    return 0;
}