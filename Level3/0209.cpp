#include<iostream>
#include<cstring>
using namespace std;

int dp[101][101], dp2[101][101];
int u[101], d[101];

int main(){
    int t;
    cin >> t;
    while(t-- > 0){
        memset(dp, 0x3f, sizeof(dp));
        memset(dp2, 0x3f, sizeof(dp2));
        memset(u, 0, sizeof(u));
        memset(d, 0, sizeof(d));
        int n;
        cin >> n;
        int a[n];
        for(int i = 0; i < n; i++)  cin >> a[i];
        for(int i = 0; i < n; i++)  dp[i][1] = dp2[i][1] = 0;
        for(int i = 1; i < n; i++){
            for(int j = 2; j <= i+1; j++){
                for(int k = 0; k < i; k++){
                    if(dp[k][j-1] > 1e9 || a[k] >= a[i] || dp[k][j-1] >= a[i]-a[k])    continue;
                    dp[i][j] = min(dp[i][j], a[i]-a[k]);
                }
            }
        }
        for(int i = n-2; i >= 0; i--){
            for(int j = 2; j <= n-1-i+1; j++){
                for(int k = n-1; k > i; k--){
                    if(dp2[k][j-1] > 1e9 || a[i] <= a[k] || a[i]-a[k] <= dp2[k][j-1])  continue;
                    dp2[i][j] = min(dp2[i][j], a[i]-a[k]);
                }
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = 1; j <= n; j++){
                if(dp[i][j] <= 1e9)  u[i] = j;
                if(dp2[i][j] <= 1e9) d[i] = j;
            }
        }
        // for(int i = 0; i < n; i++) cout << u[i] << " \n"[i+1==n];
        // for(int i = 0; i < n; i++) cout << d[i] << " \n"[i+1==n];
        int ans = 0;
        for(int i = 0; i < n; i++)    ans = max(ans, u[i]+d[i]-1);
        cout << ans << endl;
    }
    return 0;
}