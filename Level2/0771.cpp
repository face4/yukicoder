#include<iostream>
using namespace std;

int main(){
    int n;
    cin >> n;

    int dp[n][1<<n];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 1<<n; j++){
            dp[i][j] = 2001;
        }
    }
    for(int i = 0; i < n; i++)  dp[i][1<<i] = 0;

    int a[n], b[n];
    for(int i = 0; i < n; i++)  cin >> a[i] >> b[i];

    for(int s = 0; s < 1<<n; s++){
        for(int i = 0; i < n; i++){
            if((1<<i) & ~s) continue;
            for(int j = 0; j < n; j++){
                if((1<<j) & s)  continue;
                dp[j][s|(1<<j)] = min(dp[j][s|(1<<j)], max(dp[i][s], a[j]+b[i]-a[i]));
            }
        }
    }

    int ans = 2001;
    for(int i = 0; i < n; i++)  ans = min(ans, dp[i][(1<<n)-1]);

    cout << ans << endl;

    return 0;
}