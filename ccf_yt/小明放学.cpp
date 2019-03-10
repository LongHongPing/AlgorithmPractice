#include<iostream>
using namespace std;
 
int main(){
    int r, y, g;
    cin >> r >> y >> g;
    int totTime = r + y + g;
    int n;
    cin >> n;
    long long tot = 0;
    for(int i = 0; i < n; i++){
        int k, t;
        cin >> k >> t;
        if(k == 0){
            tot += t;
            continue;
        }else if(k == 1){
            t = (r - t + tot) % totTime;
        }else if(k == 2){
            t = (y - t + r + g + tot) % totTime;
        }else if(k == 3){
            t = (g - t + r + tot) % totTime;
        }
 
        if(t <= r){
            tot += (r - t);
        }else if(t >= r + g){
            tot += totTime - t;
            tot += r;
        }
    }
    cout << tot << endl;
    return 0;
}
