#include<iostream>
#include<string>

#define maxLen 100

using namespace std;

bool isDig(char c){
	/*
	if(c < '0' && c > '9'){
		return false;
	}
	else
		return true;
	*/

	return c>='0'&& c<='9';
}

void print(char c,int repeat){
	for(int i = 0;i < repeat;i++){
		cout<<c;
	}
}

int main(){
	char str[maxLen];
	char charStack = '\0';
	int repeat,temp;

	cin>>str;

	for(int i = 0;str[i] != '\0';i++){
		if(charStack == '\0'){
			charStack = str[i];
		}
		else{
			if(isDig(str[i])){
				repeat = str[i] - '0';
				while(isDig(str[++i])){
					repeat *= 10;
					temp = str[i] - '0';
					repeat += temp; 
				}
				print(charStack,repeat);
			}
			else{
				print(charStack,1);
			}

			i--;    //ǰ������һ��

			charStack = '\0';           //����վͻ��������
		}
	}
	
	//��ӡ���һ��
	if(charStack != '\0'){
		cout<<charStack<<endl;
	}

	system("pause");
	return 0;
}