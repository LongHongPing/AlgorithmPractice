#include<iostream>

#define maxSize 31

using namespace std;

int n;
int martix[maxSize][maxSize];
int u[4] = {0,-1,0,1};
int v[4] = {1,0,-1,0}; //四个方向

void dfs(int x, int y){
    if(x >= 0 && x <= n + 1 && y >= 0 && y <= n + 1){		//边界判断
		if(martix[x][y] == 1 || martix[x][y] == 3){  
			return ;
		}	
        else{
			martix[x][y] = 3;		//3为圈外的0
			for(int i = 0;i < 4;i++){
				int dx = x+u[i],dy = y+v[i];
				dfs(dx,dy);  //深搜
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
			if(martix[i][j] == 3){		//恢复圈外0
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