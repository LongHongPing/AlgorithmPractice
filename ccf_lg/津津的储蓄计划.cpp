#include<iostream>
#define maxSize 13
using namespace std; 

int main(){
	int month[maxSize];
	int money = 0,posit = 0,result;
	
	for(int i = 1;i <= 12;i++){
		cin>>month[i];
	}
	
	for(int i = 1;i <= 12;i++){
		money = money+300-month[i];
		//cout<<i<<":"<<money; 
		if(money < 0){
			cout<<(-1)*i;
			return 0;
		}
		
		int j = money/100;
		
		if(j>0){
			posit += j*100;
			money -= j*100; 
		//	cout<<","<<posit<<endl;
		}
	}
	cout<<money + posit*1.2;
	return 0;
}
