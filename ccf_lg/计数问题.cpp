#include<iostream>

using namespace std;

int c = 0;

void f(int i,int x){
    while(i != 0){
        int d = i%10;
        if(d == x){
            c++;
        }
        i /= 10;
    }
}

int main(){
    int n,x;
    cin>>n>>x;
    
    if(n > x){
        c++;
        if(n>9){
            for(int i = 10;i <= n;i++){
                f(i,x);
            }
        }
    }
    
    if(x !=0){
    	cout<<c;
	}else{
		cout<<c-1;
	}
    
    
    return 0; 
}
