#include<iostream>

using namespace std;

int main(){
	int k,n = 1;
	double sum = 0;
	cin>>k;
	
	while(sum <= k){
		sum += (double)1/n;
		n++;
		//cout<<"1/n="<<(double)1/n<<",sum="<<sum<<endl;
	}
	cout<<n-1;
	return 0;
}
