#include<iostream>
using namespace std;

int n, ans = 0, a[14] = {};

int dfs(int score, int bitset){
    if(bitset == (1<<n)-1){
        return score;
    }

    int ret = 0;
    for(int i = 0; i < n; i++){
        if(bitset & 1<<i)   continue;
        for(int j = i+1; j < n; j++){
            if(~bitset & 1<<j){
                ret = max(ret, dfs(score ^ (a[i] + a[j]), bitset^1<<i^1<<j));
            }
        }
        // ここのbreakが大事
        break;
    }

    return ret;
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++)  cin >> a[i];
    cout << dfs(0,0) << endl;
}