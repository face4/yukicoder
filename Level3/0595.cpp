#include<iostream>
#include<vector>
using namespace std;

typedef long long ll;

int main(){
    int n;
    ll p;
    cin >> n >> p;
    ll h[n];
    for(int i = 0; i < n; i++)  cin >> h[i];
    vector<vector<ll>> dp(2, vector<ll>(n, 1ll<<60));
    dp[0][0] = dp[1][0] = 0;
    for(int i = 1; i < n; i++){
        dp[0][i] = min(min(dp[0][i-1],dp[1][i-1])+p, i==1 ? 1ll<<60 : dp[0][i-1]+max(0ll, h[i-1]-h[i]));
        dp[1][i] = min(min(dp[0][i-1],dp[1][i-1])+p, dp[1][i-1]+max(0ll, h[i]-h[i-1]));
    }
    cout << min(dp[0].back(), dp[1].back()) << endl;
    return 0;
}