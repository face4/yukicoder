#include<iostream>
#include<algorithm>
using namespace std;

int dp[3001][3001] = {};

int main(){
    int n;
    cin >> n;
    int a[n+1], b[n+1], d[n+1];
    for(int i = 0; i <= n; i++) cin >> a[n-i];
    for(int i = 0; i <= n; i++) cin >> b[n-i];
    for(int i = 0; i < n; i++)  cin >> d[i];
    d[n] = 1<<30;
    sort(d, d+n+1);
    dp[0][0] = a[0]+b[0] >= d[0];
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= n; j++){
            if(i+1 <= n)    dp[i+1][j] = max(dp[i+1][j], dp[i][j]+(a[i+1]+b[j] >= d[dp[i][j]]));
            if(j+1 <= n)    dp[i][j+1] = max(dp[i][j+1], dp[i][j]+(a[i]+b[j+1] >= d[dp[i][j]]));
        }
    }
    cout << max(dp[n-1][n], dp[n][n-1]) << endl;
    return 0;
}