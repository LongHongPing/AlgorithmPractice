#include<iostream>
#include<math.h>

#define PI 3.1415926
#define IRON_DENSITY 7.86
#define GOLD_DENSITY 19.3

using namespace std;

int main(){
	double iron_dia,gold_dia;
	double iron_qua,gold_qua;

	cin>>iron_dia>>gold_dia;     //单位mm

	iron_qua = IRON_DENSITY*(4*PI*pow((iron_dia/2)*0.1,3)/3);              //转换会产生精度损失问题
	gold_qua = GOLD_DENSITY*(4*PI*pow((iron_dia/2)*0.1,3)/3);
	
	printf("%.3lf %.3lf",iron_qua,gold_qua);

	system("pause");
	return 0;
}