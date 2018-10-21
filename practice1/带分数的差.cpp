#include <iostream>

#define maxSize 200

using namespace std;
 
int numList[6] = {0};         

int symbol[2] = {1};        
 
int abs(int num){                  
	return num > 0 ? num : num*-1;
}

int comFac(int a,int b){               
	return b ? comFac(b,a%b) : a;
}

int comMul(int a,int b){            
	if(a == 0 && b == 0)
		return 0;
	return
		(a*b/comFac(a,b));
}

bool isDigit(char c){
	return '0' <= c && c <= '9';
}

int buildNum(char* numStack,int top){               
	int i;

	if(top == 0) 
		return 0;
	
	int sum = 0;

	for(i = 0;i < top;i++){
		sum *= 10;
		sum += numStack[i]-'0';            
	}
	return sum;
}

void checkNum(int& a, int& b,int& c){
	if(c == 0 && b != 0){                    //缺a时，a和b分别应为b和c的值 
		int temp = c;
		c = b;
		b = a;
		a = temp;
	}
	else if(c == 0 && b == 0)
		c = 1;         //分母不为0
}
 
void initNumList(char* str){
	int i;
	int listTop = 0,stackTop = 0;
	char numStack[maxSize] = {'\0'};
	
	for(i = 0;i < 6;i++)
		numList[i] = 0;
	for(i = 0;i < 2;i++)
		symbol[i] = 1;
	
	// 找数字 
	for(i = 0;str[i] != '\0';i++){
		if(str[i] == '-'){
			symbol[listTop/3] = -1;
		} 
		else if (isDigit(str[i])){
			numStack[stackTop++] = str[i];
		} 
		else{
			if(stackTop != 0){
				int num = buildNum(numStack,stackTop);
				numList[listTop++] = num;
				stackTop = 0;
			}
			if(str[i] == ',')
				listTop = 3;//   m2开始 
		}
	}
	
	if(stackTop != 0){
		int num = buildNum(numStack,stackTop);
		numList[listTop++] = num;
		stackTop = 0;
	}

	for(i = 0;i < 6;i += 3){
		checkNum(numList[i],numList[i+1],numList[i+2]);
	}
}

int getNum(int index){
	return numList[index-1];
}

void print(int b,int c){
	int a,common;
	if(b==0){
		cout<<0<<endl;
		return;	
	}

	bool negative = b < 0 ? true : false;
	
	b = abs(b);

    //化简
	common = comFac(b,c);     
	b = b/common;
	c = c/common;      
	a = b/c;
	b = b%c;     
	
	if(negative)
		cout<<"-";
	if(a == 0)
		cout<<"["<<b<<"/"<<c<<"]"<<endl;
	else if(b == 0)
		cout<<a<<endl;
	else 
		cout<<a<<"["<<b<<"/"<<c<<"]"<<endl;
}
 
int main(){
	char str[maxSize] = {'\0'};
	cin >> str;
	initNumList(str);
	
	int m1=getNum(1),n1=getNum(2),p1=getNum(3);
	int m2=getNum(4),n2=getNum(5),p2=getNum(6);
	
	int c = comMul(p1,p2);
	int b = (m1*p1+n1)*(c/p1)*symbol[0] - (m2*p2+n2)*(c/p2)*symbol[1];
	print(b,c);
	
	system("pause");
	return 0;
}