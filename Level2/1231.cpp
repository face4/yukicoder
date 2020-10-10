#include<iostream>
#include<cstring>
using namespace std;

int main(){
    int n;
    cin >> n;
    int x[n];
    for(int i = 0; i < n; i++)  cin >> x[i];
    int dp[n+1][10];
    memset(dp, -1, sizeof(dp));
    dp[0][0] = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 10; j++){
            if(dp[i][j] != -1)  dp[i+1][(j+x[i])%10] = max(dp[i+1][(j+x[i])%10], dp[i][j]+1);
        }
        for(int j = 0; j < 10; j++) dp[i+1][j] = max(dp[i][j], dp[i+1][j]);
    }
    cout << max(0, dp[n][0]) << endl;
    return 0;
}