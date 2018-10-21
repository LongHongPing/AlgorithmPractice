#include<iostream>

#define maxSize 100

using namespace std;

void sort(int num[],int low,int high){
	if(low >= high){
        return;
    }
    int first = low,last = high;
    int key = num[first];
 
    while(first < last){
        while(first < last && num[last] >= key)
        {
            --last;
        }
 
        num[first] = num[last];
 
        while(first < last && num[first] <= key)
        {
            ++first;
        }
         
        num[last] = num[first];    
    }
    num[first] = key;
    sort(num, low, first-1);
    sort(num, first+1, high);
}

int judge(int num[],int size){
	int tole;

	tole = num[1]-num[0];

	for(int i = 2;i < size;i++){
		if(num[i]-num[i-1] != tole){
			return 0;
		}
	}
	return tole;
}

int main(){
	int T,n,i,j;
	int num[maxSize],result[maxSize];

	cin>>T;

	for(i = 0;i < T;i++){
		cin>>n;
		
		for(j = 0;j < n;j++){
			cin>>num[j];
		}

		sort(num,0,n-1);
		
		/*
		for(j = 0;j < n;j++){
			cout<<num[j]<<" ";
		}
		*/

//		cout<<endl;
		
		result[i] = judge(num,n);
		
		//cout<<result[i]<<endl;
	}

	for(i = 0;i < T;i++){
		if(result[i] == 0){
			cout<<"no"<<endl;
		}
		else{
			cout<<result[i];
		}
	}

	system("pause");
	return 0;
}