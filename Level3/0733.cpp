#include<iostream>
#include<vector>
using namespace std;

int main(){
    int T, n;
    cin >> T >> n;
    vector<int> t(n);
    for(int i = 0; i < n; i++)  cin >> t[i];
    vector<int> dp(1<<n, 0);
    for(int s = 1; s < 1<<n; s++){
        for(int i = 0; i < n; i++){
            if(s>>i&1)  dp[s] += t[i];
        }
        if(dp[s] <= T)   dp[s] = 1;
        else             dp[s] = n;
        int sub = s;
        do{
            dp[s] = min(dp[s], dp[s-sub]+dp[sub]);
            sub = (sub-1)&s;
        }while(sub != s);
    }
    cout << dp.back() << endl;
    return 0;
}