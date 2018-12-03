#include<iostream>

using namespace std;

#define maxSize 11

int main(){
	int a[maxSize],b[maxSize];
	int max = 0,i,day;
	bool done = false;

	for(i = 0;i < 7;i++){
		cin>>a[i]>>b[i];
	}

	for(i = 0;i < 7;i++){
		if(a[i]+b[i] > 8 && max < a[i]+b[i]){
			cout<<"i:"<<i<<endl;
			max = a[i]+b[i];
			day = ++i;
			done = true;
		}
	}

	if(done){
		cout<<day;
	}
	else{
		cout<<"0";
	}

	system("pause");
	return 0;
}