#include<iostream>
using namespace std;
typedef long long ll;

ll dp[400][21] = {};

int main(){
    int n, m, start;
    cin >> n >> m >> start;
    int a[n+1];
    for(int i = 0; i < n+1; i++)    cin >> a[i];
    dp[0][0] = start;
    for(int i = 1; i < n+1; i++){
        for(int j = 0; j <= m; j++) dp[i][j] = dp[i-1][j];
        for(int j = 1; j <= m; j++){
            for(int k = 0; k < i; k++){
                if(dp[k][j-1] == 0) continue;
                dp[i][j] = max(dp[i][j], dp[k][j-1]+dp[k][j-1]/a[k]*(a[i]-a[k]));
            }
        }
    }
    ll ret = 0;
    for(int i = 0; i <= m; i++) ret = max(ret, dp[n][i]);
    cout << ret << endl;
    return 0;
}