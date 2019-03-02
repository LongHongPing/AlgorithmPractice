#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

string reverse(string s) {
    int zeroCount = 0;
    reverse(s.begin(), s.end()); 
    for (auto i : s){
    	if (i == 48) {
    		++zeroCount;
		}
        else {
        	break;
		}
	}
    s.erase(s.begin(), s.begin() + zeroCount);
    return (s != "" ? s : "0");
}

string tail(string s) { 
    int zeroCount = 0;
    for (int i = s.size() - 1; i >= 0; --i){
    	if (s[i] == 48){
    		++zeroCount;
		} 
        else{
        	break;
		} 
	}
    s.erase(s.end() - zeroCount, s.end());
    return (s != "" ? s : "0");
}

int main() {
    string s;
    cin >> s;
    if (s.back() == '%') {
        std::cout << reverse(s.substr(0, s.size() - 1)) << "%" << std::endl;
        return 0;
    }
    for (auto i : s) {
        std::string left, right;
        if (i == '/') {
            left = s.substr(0, s.find("/"));
            right = s.substr(s.find("/") + 1);
            std::cout << reverse(left) << "/" << reverse(right) << std::endl;
            return 0;
        }
        if (i == '.') {
            left = s.substr(0, s.find("."));
            right = s.substr(s.find(".") + 1);
            std::cout << reverse(left) << "." << tail(reverse(right)) << std::endl;
            return 0;
        }
    }
    std::cout << reverse(s) << std::endl;
    return 0;
}
