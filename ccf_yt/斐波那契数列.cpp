#include<bits/stdc++.h>

using namespace std;

int Memo[1001]; 

int fib1(int n);
int fib2_memo(int n);
int fib2(int n,int Memo[]);
int fib3(int n);

int fib1(int n){
	if(n<=0){
		return 0;
	}
    if(n==1){
    	return 1;
	}    
    return fib1(n-1)+fib1(n-2);
}

int fib2_memo(int n){
    if(n<=0){
    	return n;
	}       
    memset(Memo,-1,sizeof(Memo));
    return fib2(n,Memo);
}
int fib2(int n,int Memo[]){
    if(Memo[n]!=-1){
    	return Memo[n];
	}       
    //如果已经求出了fib（n）的值直接返回
	//否则将求出的值保存在Memo备忘录中。               
    if(n<=2){
    	Memo[n]=1;
	}else{
		Memo[n]=fib2(n-1,Memo)+fib2(n-2,Memo); 
	}  
    return Memo[n];
}

int fib3(int n){
    if(n<=0){
    	return n;
	}      
    Memo[0]=0;
    Memo[1]=1;
    for(int i=2;i<=n;i++){
        Memo[i]=Memo[i-1]+Memo[i-2];
    }       
    return Memo[n];
}

int main(){
	int n;
	cin>>n;
	
	//cout<<"递归:"<<fib1(n)<<endl;
	
	fib2_memo(n);
	cout<<"自顶向下:"<<fib2(n,Memo)<<endl;
	
	cout<<"自底向上:"<<fib3(n);
	return 0;
}
