#include <iostream>

#define maxSize 100

using namespace std;      

bool isPrime(int m){
	for(int i = 2;i <= sqrt(m)+1;i++){
		if(m%i == 0)
			return false;
	}
	return true;
}

bool isDigit(char c){
	return c >= '0' && c <= '9';
}

int buildNum(char* numStack,int top){                
	int i;

	if(top == 0) 
		return 0;
	
	int sum = 0;

	for(i = 0;i < top;i++){
		sum *= 10;
		sum += numStack[i]-'0';            //转为数值
	}
	return sum;
}

int getData(char *str){
    int sum = 0;
    while(*str){
        if(*str >= '0' && *str <= '9'){
            sum=sum*10+*str-'0';
        }
        str++;
    }
    return sum;
}

int maxPrimeFactor(int n){
	int i,factor = 0;

	for(i = 2;i <= sqrt(n)+1;i++){
		while(n%i == 0){
			factor = i;
			n /= i;
		}
	}
	
	if(n > 1){
		factor = n;
	}
		
	return factor;
}

/*
要是没想错，这题应该是求得最大素因子，毕竟最大因子都是它自身啊
*/
int main(){
	char str[maxSize] = {'\0'};
	int num[maxSize],factor[maxSize];
	int i,j;
	
	for(i = 0; ;i++){
		gets_s(str);
		
		
		if(strcmp(str,"    ") == 0){        //四个空格
			break;
		}
		

		num[i] = getData(str);
		//cout<<num[i]<<endl;

		if(isPrime(num[i]) || num[i] == 0){
			factor[i] = num[i];
		}
		else{
			factor[i] = maxPrimeFactor(num[i]);
		}

	}
	
	for(j = 0;j < i;j++){
		cout<<factor[j]<<endl;
	}

	system("pause");
	return 0;
}