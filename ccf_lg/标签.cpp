#include<bits/stdc++.h>

using namespace std;

void read();
void search();
void query();

struct element{
	int father;
	string id,label;
};
vector<element> elements(105);
vector<vector<int>> series;
vector<string> vec;
vector<int> ans;
string line;
int n,m;

void read(){
	for(int i = 1;i <= n;i++){
		getline(cin,line);
		int j = 0,k = 0;
		while(line[j] == '.'){
			j++;
		}
		for(int k = j;k < line.size() && line[k] != ' ';k++);
		if(series.size() <= j/2){
			series.push_back({i});
		}else{
			series[j/2].push_back(i);
		}
		elements[i].label = line.substr(j,k-j);
		for(auto &c : elements[i].label){
			c = tolower(c);
		}
		elements[i].id = (k == line.size()) ? "" : line.substr(k+1);
		elements[i].father = j/2-1 < 0 ? -1 : series[j/2-1].back();
	}
}

void search(){
	while(m--){
		getline(cin,line);
		for(int i = 0;i < line.size();i++){
			int j = i;
			while(j < line.size() && line[j] != ' '){
				j++;
			}
			string s = line.substr(i,j-i);
			if(s[0] != '#'){
				for(auto &c : s){
					c = tolower(c);
				}
			}
			vec.push_back(s);
			i = j;
		}
		query();
	}
}

void query(){
	for(int i = vec.size()-1;i < series.size();i++){
		for(int j : series[i]){
			if(elements[j].label == vec.back() || 
			   elements[j].id ==vec.back()){
				int k = vec.size()-2;
				for(int p = elements[j].father;k >= 0 && p != -1;p = elements[p].father){
					if(elements[p].label == vec[k] || elements[p].id == vec[k]){
						k--;
					}
				}
				if(k < 0){
					ans.push_back(j);
				}
			}
		}
		cout<<ans.size()<<" ";
		for(auto i : ans){
			cout<<i<<" ";
		}
		cout<<endl;
	}
}

int main(){
	cin>>n>>m;
	read();
	search();
	return 0;
} 
