#include<iostream>

using namespace std;

int main(){
	int a,b;
	int c,d;
	cin>>a>>b>>c>>d;

	int e,f;

	if(d-b < 0){
		f = d+60-b;
		e = c-1-a;
	}
	else{
		f = d-b;
		e = c-a;
	}

	cout<<e<<" "<<f<<endl;

	system("pause");
	return 0;
}