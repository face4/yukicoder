#include<iostream>
#include<vector>
using namespace std;

static const int INF = 1<<29;

int main(){
    int n, c, v;
    cin >> n >> c >> v;

    int s[v], t[v], y[v], m[v];
    for(int i = 0; i < v; i++)  cin >> s[i];
    for(int i = 0; i < v; i++)  cin >> t[i];
    for(int i = 0; i < v; i++)  cin >> y[i];
    for(int i = 0; i < v; i++)  cin >> m[i];

    int dp[51][301];
    for(int i = 0; i < 51; i++){
        for(int j = 0; j < 301; j++){
            dp[i][j] = INF;
        }
    }

    dp[1][c] = 0;
    
    for(int i = 1; i <= n; i++){
        for(int j = c; j >= 0; j--){
            if(dp[i][j] != INF){
                for(int k = 0; k < v; k++){
                    if(i == s[k] && j - y[k] >= 0){
                        dp[t[k]][j-y[k]] = min(dp[t[k]][j-y[k]], dp[i][j] + m[k]);
                    }
                }
            }
        }
    }

    int ans = INF;
    for(int i = 0; i <= c; i++) ans = min(ans, dp[n][i]);
    if(ans == INF)  ans = -1;
    
    cout << ans << endl;

    return 0;
}