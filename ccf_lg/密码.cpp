#include<iostream>

using namespace std;

int main(){
	int n;
	string s;
	cin>>n;
	cin>>s;
	
	for(int i = 0;i < s.length();i++){
		s[i] = (s[i]-'a'+n)%26+'a';
	}
	cout<<s;
	return 0;
} 
