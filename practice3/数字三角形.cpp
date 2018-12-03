#include<iostream>

#define maxSize 30

using namespace std;

int main(){
	int m,ans = 0;
	int num[maxSize][maxSize],sum[maxSize][maxSize];
	cin>>m;

	for(int i = 1;i <= m;i++){
		for(int j = 1;j <= i;j++){
			cin>>num[i][j];
		}
	}

	memset(sum,0,sizeof(sum));

	/*
	for (int i = 1;i <= m;i ++)
        for (int j = 1;j <= i;j ++){
            if (j == 1) sum[i][j] = num[i][j] + sum[i-1][j];
            else if (j == m) sum[i][j] = num[i][j] + sum[i-1][j-1];
            else sum[i][j] = max(sum[i-1][j], sum[i-1][j-1]) + num[i][j];
        }
    for (int i = 1;i <= m;i ++) 
		ans = max(ans, sum[m][i]);

	cout<<ans;
*/

	for (int i = m;i >= 1;i --)
        for (int j = 1;j <= i;j ++)
            sum[i][j] = max(sum[i+1][j], sum[i+1][j+1]) + num[i][j];
	
	cout<<sum[1][1];
	system("pause");
	return 0;
}