#include<iostream>

using namespace std;

int main(){
	int a,b,c;
	//int result_a[1000],result_b[1000],result_c[1000];

	//int i = 0,j;

	for(a = 0;a <= 9;a++){
		for(b = 0;b <= 9;b++){
			for(c = 0;c<=9;c++){
				if(a*100+b*10*2+c+c*100+a == 1333){
					cout<<a<<","<<b<<","<<c<<endl;
					/*result_a[i] = a;
					result_b[i] = b;
					result_c[i] = c;
					i++;
					*/
				}
			}
		}
	}

	/*j = i;
	if(i == 0)
		cout<<"none"<<endl;
	else
		for(i = 0;i < j;i++){
		cout<<result_a[i]<<","<<result_b[i]<<","<<result_c[i]<<endl;
	}
	*/
	system("pause");
	return 0;
	
}