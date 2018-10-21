#include<iostream>
#include<stdio.h>

#define maxSize 100

using namespace std;

double fun(int num){
	double result;
	if(num == 1){
		result = 1;
	}
	else{
		result = 1/(1+fun(num-1));
	}
	return result;
}

int main(){
	int m,i;
	int num[maxSize];
	double result[maxSize];

	cin>>m;
	
	for(i = 0;i < m;i++){
		cin>>num[i];
	}

	for(i = 0;i < m;i++){
		result[i] = fun(num[i]);
	}

	for(i = 0;i < m;i++){
		printf("%.6lf\n",result[i]);
	}
	system("pause");
	return 0;
}