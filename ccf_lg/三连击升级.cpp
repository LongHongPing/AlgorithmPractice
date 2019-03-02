#include<iostream>
#include<string.h>

using namespace std;

int d[10];
int g;
void f(int x){
	while(x != 0){
		g = x%10;
		d[g] += 1;
		x /= 10;
	}
}

int main(){
	double a,b,c;
	bool done = false;
	cin>>a>>b>>c;
	
	b /= a;
	c /= a;
	//cout<<"b="<<b<<"c="<<c<<endl;
	memset(d,0,sizeof(d));
	for(int i = 123;i < 987;i++){  
		double j = i*b;
		double k = i*c;
		
		if(k > 987 || j > 987){
			break;
		}
		
		f(i);
		f(j);
		f(k);
		
		if(d[1] == 1 &&d[2] == 1 &&d[3] == 1 &&d[4] == 1 
		 &&d[5] == 1 &&d[6] == 1 &&d[7] == 1 &&d[8] == 1 &&d[9] == 1){
		 	cout<<i<<" "<<j<<" "<<k<<endl;
		 	done = true;
		 }
		memset(d,0,sizeof(d));
	}
	
	if(!done){
		cout<<"No!!!";
	}
	
	return 0; 
}




