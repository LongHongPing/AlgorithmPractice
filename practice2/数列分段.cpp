#include<iostream>

#define maxSize 100000

using namespace std;

int main(){
    int n,m,i;
    int a[maxSize];
    int segment = 0,sum = 0;
    
    cin>>n>>m;
    for(i = 0;i < n;i++){
        cin>>a[i];
    }
    
    for(i = 0;i < n;i++){     
        if(sum+a[i] > m){		将数列小于等于m的分为一段
            segment++;
            sum = 0;
        }
		sum += a[i];
    }
    
    //cout<<sum<<","<<segment<<endl;
    if(sum <= m){		//剩下的数
        segment++;
    }
    
    cout<<segment<<endl;
    
	system("pause");
    return 0;
}
