#include<iostream>
using namespace std;

int main(){
    int t, n;
    cin >> t >> n;

    int c[n+1], v[n+1];
    for(int i = 1; i <= n; i++)  cin >> c[i];
    for(int i = 1; i <= n; i++)  cin >> v[i];
    
    int dp[16][10001];
    for(int i = 0; i < 16; i++){
        for(int j = 0; j < 10001; j++){
            dp[i][j] = -1;
        }
    }

    dp[0][0] = 0;

    for(int i = 1; i <= n; i++){
        int sum = 0;
        for(int cnt = 1; cnt*c[i] <= t && v[i] > 0; cnt++){
            sum += v[i];
            v[i] /= 2;
            for(int j = cnt*c[i]; j <= t; j++){
                if(dp[i-1][j-cnt*c[i]] == -1)   continue;
                dp[i][j] = max(dp[i][j], dp[i-1][j-cnt*c[i]]+sum);
            }
        }
        for(int j = 0; j <= t; j++) dp[i][j] = max(dp[i-1][j], dp[i][j]);
    }

    int ans = 0;
    for(int j = 0; j <= t; j++) ans = max(ans, dp[n][j]);

    cout << ans << endl;
    
    return 0;
}