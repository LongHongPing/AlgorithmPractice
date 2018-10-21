#include<iostream>

#define maxSize 100

using namespace std;

void sort(char str[],int low,int high){
	if(low >= high){
        return;
    }
    int first = low,last = high;
    char key = str[first];
 
    while(first < last){
        while(first < last && str[last] >= key)
        {
            --last;
        }
 
        str[first] = str[last];
 
        while(first < last && str[first] <= key)
        {
            ++first;
        }
         
        str[last] = str[first];    
    }
    str[first] = key;
    sort(str, low, first-1);
    sort(str, first+1, high);
}

int main(){
	char str[maxSize] = {0},left[maxSize],right[maxSize];
	char key;

	gets_s(str);
	key = str[0];

	int i,r = 0,l = 0;
	for(i = 1;str[i] != '\0';i++){
		if(str[i] <= key){
			right[r++] = str[i];
		}
		else{
			left[l++] = str[i];
		}
	}

	sort(right,0,r-1);
	
	for(i = 0;i < l;i++){
		cout<<left[i];
	}

	cout<<key;
	
	for(i = 0;i < r;i++){
		cout<<right[i];
	}

	system("pause");
	return 0;
}