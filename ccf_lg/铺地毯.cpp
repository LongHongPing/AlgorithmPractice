#include<bits/stdc++.h>

using namespace std;

struct dt{
	int a,b,g,k;
};

int main(){
	int n,x,y;
	cin>>n;
	dt d[n+1];
	for(int i = 1;i <= n;i++){
		cin>>d[i].a>>d[i].b>>d[i].g>>d[i].k;
		d[i].g += d[i].a;
		d[i].k += d[i].b;
	}
	cin>>x>>y;
	
	int ans = -1;
	while(n >= 1){
		if(d[n].a <= x && d[n].b <= y && d[n].g >= x && d[n].k >= y){
			ans = n;
			break;
		}
		n--;
	}
	cout<<ans;
	return 0;
}
