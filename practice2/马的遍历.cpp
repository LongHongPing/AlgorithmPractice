#include<iostream>
#include<cstring>
#include<cstdio>

#define maxSize 400001
#define size 401

using namespace std;

struct queue_{
    int x,y;
}que[maxSize];

int head = 0,tail = 1;
int n,m,i,j;		//棋盘的大小和马的坐标
int get_[size][size];		//结果
int u[8] = {2,-2,2,-2,-1,1,-1,1};
int v[8] = {1,1,-1,-1,2,2,-2,-2};//方向

void bfs(){
	//第一个点
	get_[i][j] = 0;
    que[1].x = i;
    que[1].y = j;

    while(head < tail){
        head++;

        int s = get_[que[head].x][que[head].y]+1; //下一个点步数+1
        
		for(int k = 0;k < 8;++k){
            int dx = que[head].x+u[k],dy = que[head].y+v[k];
            if(get_[dx][dy] == -1 && dx >= 1 && dx <= n && dy >= 1 && dy <= m){			//边界
                tail++;
                que[tail].x = dx;
                que[tail].y = dy;
                get_[dx][dy] = s;
            }
        }
    }
}

int main(){
    cin>>n>>m>>i>>j;

	memset(get_,-1,sizeof(get_));	//初始化

    bfs();

    for(int k = 1;k <= n;++k){
		for(int l = 1;l <= m;++l){
			 printf("%-5d", get_[k][l]);		//按格式输出
		}    
        cout<<endl;
    }

	system("pause");
    return 0; 
}