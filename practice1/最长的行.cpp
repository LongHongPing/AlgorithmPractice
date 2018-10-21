#include<iostream>
#include<string>

#define max 100

using namespace std;

int main(){
	int length,count = 0,maxLen = 0;

	//string str[max],maxStr;
	char maxStr[max],str[max];

	for(int i = 0;i < max;i++){
		gets_s(str);
		
		//count++;
		
		/*
		if(str == "***end***"){
			break;
		}
		*/
		if(strcmp(str,"***end***") == 0){
			break;
		}

		length = strlen(str);
		if(maxLen < length){
			maxLen = length;
			strcpy_s(maxStr,str);
		}
			
	}

	/*
	length[0] = str[0].length();
	maxLen = str[0].length();
	maxStr = str[0];

	for(i = 1;i < count-1;i++){
		length[i] = str[i].length();
		
		if(length[i] > maxLen){
			maxLen = length[i];
			maxStr = str[i];
		}
	}
	*/

	cout<<maxLen<<endl;
	cout<<maxStr<<endl;

	system("pause");
	return 0;
}