// 自力AC
#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;

int dp[2][3000][3000] = {};

int main(){
    int n, m;
    cin >> n >> m;
    if(m <= 1){
        cout << 0 << endl;
        return 0;
    }
    vector<int> v(n);
    for(int i = 0; i < n; i++)  cin >> v[i];
    
    // 最初の頂点を必ず選択する
    memset(dp, -0x3f, sizeof(dp));
    dp[1][0][1] = 0;
    for(int j = 1; j < n; j++){
        for(int k = 0; k <= m; k++){
            dp[0][j][k] = max(dp[1][j-1][k], dp[0][j-1][k]);
            if(k)   dp[1][j][k] = max(dp[1][j-1][k-1]+v[j], dp[0][j-1][k-1]);
        }
    }
    int ans = max(dp[1][n-1][m]+v[0], dp[0][n-1][m]);

    // 最初の頂点を必ず選択しない
    memset(dp, -0x3f, sizeof(dp));
    dp[0][0][0] = 0;
    for(int j = 1; j < n; j++){
        for(int k = 0; k <= m; k++){
            dp[0][j][k] = max(dp[1][j-1][k], dp[0][j-1][k]);
            if(k)   dp[1][j][k] = max(dp[1][j-1][k-1]+v[j], dp[0][j-1][k-1]);
        }
    }
    ans = max({ans, dp[0][n-1][m], dp[1][n-1][m]});

    cout << ans << endl;
    return 0;
}