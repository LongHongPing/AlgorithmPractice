#include<iostream>

#define maxSize 31

using namespace std;

int n;
int martix[maxSize][maxSize];
int u[4] = {0,-1,0,1};
int v[4] = {1,0,-1,0}; //�ĸ�����

void dfs(int x, int y){
    if(x >= 0 && x <= n + 1 && y >= 0 && y <= n + 1){		//�߽��ж�
		if(martix[x][y] == 1 || martix[x][y] == 3){  
			return ;
		}	
        else{
			martix[x][y] = 3;		//3ΪȦ���0
			for(int i = 0;i < 4;i++){
				int dx = x+u[i],dy = y+v[i];
				dfs(dx,dy);  //����
			}
		}
    }
}

int main(){
	int i,j;
    cin>>n;
	for(i = 1; i <= n; ++ i){
		for(j = 1; j <= n; ++ j){
			cin>>martix[i][j];
		}
	}
    
	dfs(0, 0);
    
	for(i = 1; i <= n; ++ i){
		for(j = 1; j <= n; ++ j){
			if(martix[i][j] == 3){		//�ָ�Ȧ��0
				martix[i][j] = 0;
			} 			
			else if(martix[i][j] == 0){
				martix[i][j] = 2;
			}	
		}
	}
    
    
	for(i = 1; i <= n; ++ i){
		for(j = 1; j <= n;++ j){
			cout<<martix[i][j]<<" ";
		}
		cout<<endl;
	}
    
    
	system("pause");
	return 0;
}