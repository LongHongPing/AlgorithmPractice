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
int n,m,i,j;		//���̵Ĵ�С���������
int get_[size][size];		//���
int u[8] = {2,-2,2,-2,-1,1,-1,1};
int v[8] = {1,1,-1,-1,2,2,-2,-2};//����

void bfs(){
	//��һ����
	get_[i][j] = 0;
    que[1].x = i;
    que[1].y = j;

    while(head < tail){
        head++;

        int s = get_[que[head].x][que[head].y]+1; //��һ���㲽��+1
        
		for(int k = 0;k < 8;++k){
            int dx = que[head].x+u[k],dy = que[head].y+v[k];
            if(get_[dx][dy] == -1 && dx >= 1 && dx <= n && dy >= 1 && dy <= m){			//�߽�
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

	memset(get_,-1,sizeof(get_));	//��ʼ��

    bfs();

    for(int k = 1;k <= n;++k){
		for(int l = 1;l <= m;++l){
			 printf("%-5d", get_[k][l]);		//����ʽ���
		}    
        cout<<endl;
    }

	system("pause");
    return 0; 
}