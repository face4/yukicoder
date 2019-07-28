#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;

const ll INF = 1ll<<60;

int main(){
    int n, m, a;
    cin >> n >> m >> a;
    vector<pair<int,int>> vp[n+1];
    while(m-- > 0){
        int l, r, p;
        cin >> l >> r >> p;
        vp[l-1].push_back({r, p});
    }
    
    vector<vector<ll>> dp(2, vector<ll>(n+1, -INF));
    dp[0][0] = dp[1][0] = 0;
    for(int i = 0; i < n; i++){
        if(i){
            dp[0][i] = max({dp[0][i-1],dp[0][i],dp[1][i-1]});
            dp[1][i] = max(dp[1][i], dp[0][i]-a);
        }   
        for(pair<int,int> p : vp[i]){
            int r = p.first, val = p.second;
            int tmp = (r == n ? 0 : a);
            dp[1][r] = max({dp[1][r], dp[1][i]+val-tmp, dp[0][i]-a+val-tmp});
        }
    }
    
    // dirty :(
    ll ans = 0;
    for(int i = 0; i < 2; i++)  for(int j = 0; j <= n; j++) ans = max(ans,dp[i][j]);
    cout << ans << endl;

    return 0;
}