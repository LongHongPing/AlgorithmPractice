#include<iostream>

#define maxSize 100

using namespace std;

int sum = 0;
int ans[maxSize],marix[maxSize][maxSize]={0};

void queen(int line,int n){
	int i;
    if(line > n){
        sum++;		//��¼��ĸ���
        if(sum > 3)			//ֻ���ǰ���ֽ�
			return;
        else{
            for(i = 1;i <= n;i++)
				cout<<ans[i]<<" ";
            cout<<endl;
            return;
        }
    }

    for(i = 1;i <= n;i++){
        if((!marix[0][i])&&(!marix[1][line+i])&&(!marix[2][line-i+n])){
            ans[line] = i;		//ռ��line��i��
            marix[0][i] = 1;			//��ռ��
			marix[1][line+i] = 1;		//�ҶԽ�ռ��
			marix[2][line-i+n] = 1;	//��Խ�ռ�У�+nΪ�˱��⸺��
            
			queen(line+1,n);
            
			marix[0][i] = 0;
			marix[1][line+i] = 0;
			marix[2][line-i+n] = 0;
        }
    }
}

int main(){
	int n;
	cin>>n;
    
	queen(1,n);
    
	cout<<sum<<endl;

	system("pause");
    return 0;
}