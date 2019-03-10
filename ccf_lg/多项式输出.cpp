#include<bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin>>n;
	int a[n+1];
	for(int i = n;i >= 0;i--){
		cin>>a[i];
	}
	
	for(int i = n;i > 0;i--){
		if(a[i] == 0){		//0项 
			continue;
		}
		
		if(i == n){		//首项
			if(a[i] == 1){
				cout<<"x^"<<i;
			}else if(a[i] == -1){
				cout<<"-x^"<<i;
			}else{
				cout<<a[i]<<"x^"<<i;
			}  
			continue;
		}
		
		if(i == 1){
			if(a[i] == 1){
				cout<<"+x";
			}else if(a[i] == -1){
				cout<<"-x";
			}else if(a[i] > 0){
				cout<<"+"<<a[i]<<"x";
			}else{
				cout<<a[i]<<"x";
			}  
			continue;
		}
		
		if(a[i] == 1){
			cout<<"+"<<"x^"<<i;
		}else if(a[i] == -1){
			cout<<"-x^"<<i;
		}else if(a[i] > 0){ 	//系数为正 
			cout<<"+"<<a[i]<<"x^"<<i;
		}else{		//为负 
			cout<<a[i]<<"x^"<<i;
		}	
	}
	//最后一项 
	if(a[0] > 0){
		cout<<"+"<<a[0];
	}else if(a[0] < 0){
		cout<<a[0];
	} 
	return 0;
}
