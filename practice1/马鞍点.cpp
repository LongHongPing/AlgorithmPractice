#include<iostream>

#define maxSize 100

using namespace std;

int main(){
	int m,n;
	int mat[maxSize][maxSize];
	int column_max[maxSize],row_min[maxSize];

	cin>>m>>n;

	for(int i = 0;i < m;i++){
		for(int j = 0;j < n;j++){
			cin>>mat[i][j];
		}
	}

	for(int i = 0; i < m; i++) {
		row_min[i] = mat[i][0];
		for(int j = 1; j < n; j++){
			if(row_min[i] > mat[i][j]){
				row_min[i] = mat[i][j];
			}
		}     
    }

    for(int j = 0;j < n;j++){
        column_max[j] = mat[0][j];
		for(int i = 1;i < m; i++){
			if(column_max[j]<mat[i][j]){
				column_max[j]=mat[i][j];
			}
                
		}
            
    }

	bool done;

	for(int i = 0;i < m;i++){
		for(int j = 0;j < n;j++){
			if(row_min[i]==column_max[j]){
                cout<<i<<" "<<j<<" "<<mat[i][j]<<endl;
                done=true;
            }
		}
            
	}
        
    if(!done)
        cout<<"no"<<endl;

	system("pause");
	return 0;
}