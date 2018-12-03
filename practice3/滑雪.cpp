#include<iostream>

#define maxSize 100

using namespace std;

int n,m;
int f[maxSize][maxSize],a[maxSize][maxSize];
/*
int u[4] = {0,-1,0,1};
int v[4] = {1,0,-1,0};
*/

int dp(int x,int y){
	if(f[x][y] != 0){
		return f[x][y];
	}
	
	//f[x][y] = 1;		初始还没滑，不应该是0吗
	f[x][y] = 0;
	
	/*
	for(int i = 0;i < 4;i++){
		int dx = x+u[i],dy = y+v[i];
		if((a[dx][dy] < a[x][y]) && (x > 1 || x < n || y >1 || y < m)){
			f[x][y] = max(f[x][y],dp(dx,dy)+1);
		}
	}
	*/

	if ((a[x - 1][y] < a[x][y])&&(x > 0))    f[x][y] = max(f[x][y], dp(x - 1, y) + 1);
    if ((a[x + 1][y] < a[x][y])&&(x < n))   f[x][y] = max(f[x][y], dp(x + 1, y) + 1); 
    if ((a[x][y - 1] < a[x][y])&&(y > 0))    f[x][y] = max(f[x][y], dp(x, y - 1) + 1); 
    if ((a[x][y + 1] < a[x][y])&&(y < m))  f[x][y] = max(f[x][y], dp(x, y + 1) + 1);

	return f[x][y];
}

int main(){
	cin>>n>>m;
	
	memset(f,0,sizeof(f));

	for(int i = 0;i < n;i++){
		for(int j= 0;j < m;j++){
			cin>>a[i][j];
		}
	}

	int max = 0,x,y;
	for(int i = 0;i < n;i++){
		for(int j= 0;j < m;j++){
			if(max < a[i][j]){
				max = a[i][j];
				x = i;
				y = j;
			}
		}
	}
	
	//cout<<max<<" "<<x<<" "<<y<<endl;

	cout<<dp(x,y);

	system("pause");
	return 0;
}

/*

1 2 3 4 5
16 17 18 19 6
15 24 25 20 7
14 23 22 21 8
13 12 11 10 9

*/