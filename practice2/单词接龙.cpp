#include<iostream>
#include<string>

#define maxSize 30

using namespace std;

int n,maxLength;
int repeat[maxSize][maxSize],visit[maxSize];
string words[maxSize];

//预处理，把重复长度存到repeat
void pre(string a,string b,int x,int y){
    int length_a = a.size()-1,length_b = b.size()-1;

    for(int i = 0;i <= length_b;i++){		//枚举
        if(a[0] == b[i]){	
            int pos=0,re=0;  //pos是当前a的第几个字母，re是a和b的重合部分长度 
            for(int j = i;j <= length_b;j++){
                if(a[pos] == b[j]){ 
                    re++;
                    pos++;
                    if(j == length_b && re != min(length_a,length_b)+1){	//不能包含
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
            int length=sum+words[i].size()-repeat[i][pos];  //新的长度
            dfs(i,length);  //接上新单词继续搜索 
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
        visit[i] = 2; //每个单词能用两次 
    }

    cin>>ch;
	for(i = 1;i <= n;i++){
		for(j = 1;j <= n;j++){
			pre(words[i],words[j],i,j); //预处理repeat数组 
		}   
	}
      

    for(i = 1;i <= n;i++){
        if(words[i][0] == ch){  //找到开始部分 
            visit[i]--;
            dfs(i,words[i].size()); //深搜 
            visit[i]++;
        }  
    }

    cout<<maxLength<<endl;

	system("pause");
    return 0;
}