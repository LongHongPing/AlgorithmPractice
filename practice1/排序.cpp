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
        while(first < last && num[last] <= key)
        {
            --last;
        }
 
        num[first] = num[last];
 
        while(first < last && num[first] >= key)
        {
            ++first;
        }
         
        num[last] = num[first];    
    }
    num[first] = key;
    sort(num, low, first-1);
    sort(num, first+1, high);
}

int main(){
	int n,e_count = 0,o_count = 0;
	int num[maxSize],odd[maxSize],even[maxSize];

	cin>>n;

	for(int i = 0;i < n;i++){
		cin>>num[i];
	}

	for(int i = 0;i < n;i++){
		if(num[i]%2 == 0){
			even[e_count++] = num[i];
		}
		else{
			odd[o_count++] = num[i];
		}
	}

	sort(even,0,e_count-1);
	for(int i = 0;i < e_count;i++){
		cout<<even[i]<<" ";
	}

	sort(odd,0,o_count-1);
	for(int i = 0;i < o_count;i++){
		cout<<odd[i]<<" ";
	}

	cout<<endl;
	system("pause");
	return 0;
}