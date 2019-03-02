#include<iostream>
#include<math.h>

using namespace std;
 
int main(){
	long long b,p,k,ans=1;
	cin>>b>>p>>k;
	cout<<b<<"^"<<p<<" mod "<<k<<"=";

	while(p > 0){
		if(p & 1){
			ans = ans*b%k;
		}
		b = b*b%k; 
		p=p>>1;
	}
	cout<<ans%k;
	return 0 ;
}


