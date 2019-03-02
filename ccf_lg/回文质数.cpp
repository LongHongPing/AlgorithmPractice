#include<iostream>
#include<math.h>

using namespace std;

bool isPrime(int x){
	int i;
	int n = sqrt(x);
    for(i=3;i<=n;i++)
        if(x%i==0) return 0;
    return 1;
}

bool isHw(int x){
 	int y=x,num=0;
    while (y!=0){
        num=num*10+y%10;
        y/=10;
    } 
    if (num==x){
    	return true;
	} 
    else{
    	return false;
	} 
}

int main(){
	int a,b;
	cin>>a>>b;
	
	if(a%2 ==0){
		a++;
	}   
	if (b>=10000000){
		b=9999999;
	}
	 
	for(int i = a;i <= b;i+=2){
		if( isHw(i) && isPrime(i)){
			cout<<i<<endl;

		}
	}
	return 0;
}
