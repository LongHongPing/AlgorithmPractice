#include<iostream>
#include<string>

#define maxSize 30

using namespace std;

int n,maxLength;
int repeat[maxSize][maxSize],visit[maxSize];
string words[maxSize];

//Ԥ�������ظ����ȴ浽repeat
void pre(string a,string b,int x,int y){
    int length_a = a.size()-1,length_b = b.size()-1;

    for(int i = 0;i <= length_b;i++){		//ö��
        if(a[0] == b[i]){	
            int pos=0,re=0;  //pos�ǵ�ǰa�ĵڼ�����ĸ��re��a��b���غϲ��ֳ��� 
            for(int j = i;j <= length_b;j++){
                if(a[pos] == b[j]){ 
                    re++;
                    pos++;
                    if(j == length_b && re != min(length_a,length_b)+1){	//���ܰ���
							repeat[x][y]=re;  
					}
                }
				else{
					break;
				} 
            }
        }
    }
}

void dfs(int pos,int sum){
    maxLength=max(maxLength,sum);   
    for(int i = 1;i <= n;i++){
        if(repeat[i][pos] && visit[i]){
            visit[i]--;
            int length=sum+words[i].size()-repeat[i][pos];  //�µĳ���
            dfs(i,length);  //�����µ��ʼ������� 
            visit[i]++;			
        }
    }
}

int main(){
	char ch;
	int i,j;

    cin>>n;
    for(int i = 1;i <= n;i++){
        cin>>words[i];
        visit[i] = 2; //ÿ�������������� 
    }

    cin>>ch;
	for(i = 1;i <= n;i++){
		for(j = 1;j <= n;j++){
			pre(words[i],words[j],i,j); //Ԥ����repeat���� 
		}   
	}
      

    for(i = 1;i <= n;i++){
        if(words[i][0] == ch){  //�ҵ���ʼ���� 
            visit[i]--;
            dfs(i,words[i].size()); //���� 
            visit[i]++;
        }  
    }

    cout<<maxLength<<endl;

	system("pause");
    return 0;
}