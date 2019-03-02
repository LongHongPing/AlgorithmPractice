#include<iostream>
#include<string.h>
using namespace std;

int d[10];
int c;
void f(int x){
	while(x != 0){
		c = x%10;
		d[c] += 1;
		x /= 10;
	}
}

int main(){
	memset(d,0,sizeof(d));
	for(int i = 123;i < 330;i++){  
		int a = i*2;
		int b = i*3;
		
		f(i);
		f(a);
		f(b);
		
		if(d[1] == 1 &&d[2] == 1 &&d[3] == 1 &&d[4] == 1 
		 &&d[5] == 1 &&d[6] == 1 &&d[7] == 1 &&d[8] == 1 &&d[9] == 1){
		 	cout<<i<<" "<<a<<" "<<b<<endl;
		 }
		 
		memset(d,0,sizeof(d));
	}
	return 0; 
}



