#include<iostream>

using namespace std;


						//ÈÃÎÒ×Ô±Õ 
int main(){
    int n,c = 0;
    cin>>n;
    int a[n],b[n];
    for (int i = 1;i <= n;i++){
        cin>>a[i]; 
        b[i] = a[i];
    }
    
	for(int i = 1;i <= n-1;i++){ 
        for(int j = i+1;j <= n;j++){  
            for(int k = 1;k <= n;k++){
                if(b[k] == a[i]+a[j]) {
                    c++;
                    b[k] = 0; 
                }
            } 
        }
    }
    
    cout<<c; 
    return 0;
}
