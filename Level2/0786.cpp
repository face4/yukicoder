#include<iostream>
using namespace std;
typedef long long ll;

int main(){
    int n;
    cin >> n;

    ll dp[100] = {};
    dp[0] = 1;

    for(int i = 0; i < n; i++){
        dp[i+1] += dp[i];
        dp[i+2] += dp[i];
    }

    cout << dp[n] << endl;
    
    return 0;
}