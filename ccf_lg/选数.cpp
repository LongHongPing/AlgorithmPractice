#include<iostream>
#include<math.h>

using namespace std;

int x[20],n,k;

bool isPrime(int n){
	if(n < 2){
		return false;
	}
	if(n == 2){
		return true;
	}
    for(int i = 2;i < sqrt(n)+1;i++){
        if(n%i == 0){
        	return false;
		}
    }
    
    return true;
}

int rule(int start,int end,int k,int al_sum){
    int sum=0;
	
	if(k==0){
		//cout<<"al_sum:"<<al_sum<<endl;
    	return isPrime(al_sum);
	}
    
    for(int i=start;i<=end;i++){
        sum+=rule(i+1,end,k-1,al_sum+x[i]);
    }
    return sum;
}

int main(){
    cin>>n>>k;
    for(int i =0;i<n;i++){
    	cin>>x[i];
	}
	
    cout<<rule(0,n-1,k,0);
    
    return 0;
}
