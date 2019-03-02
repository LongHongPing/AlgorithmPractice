#include<iostream>

using namespace std;

int main(){
	double s,x,l;
	cin>>s>>x;
	
	//cout<<s-x<<","<<s+x<<endl;
	
	for(int i = 0; ;i++){
		l = 7*i-0.07*i*i;
		if(l > s-x){
		//	cout<<l<<endl;
			i++;
			l = 7*i-0.07*i*i;
			if(l < s+x){
		//		cout<<l<<endl;
				cout<<"y";
				return 0; 
			}else{
				cout<<"n";
				return 0; 
			}
		}
	}
	
	return 0;
}
