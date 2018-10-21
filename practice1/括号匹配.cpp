#include<iostream>
#include<stack>
#include<cstring>

#define maxSize 100

using namespace std;

int main(){
    stack<char> s;
	char str[maxSize] = {'\0'},t;
	int length,result[maxSize],count = 0;

	while(1){
		gets_s(str);

		if(strcmp(str,"") == 0){
			break;
		}

		length = strlen(str);

		for(int i = 0;i < length;i++){
			if(str[i] == '(' || str[i] == '[' || str[i] == '{'){
				s.push(str[i]);
			}

			if(str[i] == ')'){
				t = s.top();
				
				if(t == '('){
					s.pop();
				}
				else{
					result[count++] = 0;
					break;
				}
			}

			if(str[i] == ']'){
				t = s.top();
				
				if(t == '['){
					s.pop();
				}    
				else{
					result[count++] = 0;
					break;
				}
			}

			if(str[i] == '}'){
				t = s.top();
				
				if(t=='{'){
					s.pop();
				}   
				else{
					result[count++] = 0;
					break;
				}
			}
		}
        result[count++] = 1;
	}
	
	for(int i = 0;i < count-1;i++){       //要去掉结束输入时多输入的那个空行
		if(result[i] == 0){
			cout<<"no"<<endl;
		}
		else{
			cout<<"yes"<<endl;
		}
	}

	system("pause");
    return 0;
}