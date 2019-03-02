#include<iostream>

using namespace std;

int x[5001],y[5001];

void sort(int num_x[],int num_y[],int low,int high){
	if(low >= high){
        return;
    }
    int first = low,last = high;
    int key_x = num_x[first],key_y = num_y[first];
 
    while(first < last){
        while(first < last && num_y[last] >= key_y)
        {
            --last;
        }
        num_y[first] = num_y[last];
        num_x[first] = num_x[last];
        
        while(first < last && num_y[first] <= key_y)
        {
            ++first;
        }
        num_x[last] = num_x[first]; 
        num_y[last] = num_y[first];    
    }
    
    num_x[first] = key_x;
    num_y[first] = key_y;
    sort(num_x,num_y, low, first-1);
    sort(num_x,num_y, first+1, high);
}

int main(){
	int n,s,a,b,cnt = 0;
	
	cin>>n>>s;
	cin>>a>>b;
	a += b; 
	for(int i = 0;i < n;i++){
		cin>>x[i]>>y[i];
	}
	
	
	sort(x,y,0,n-1);
	
	for(int i = 0;i < n;i++){
		if(s-y[i] >= 0 && a>= x[i]){
			cnt++;
			s -= y[i];
		}
	}
	
	cout<<cnt;
	return 0;
}
