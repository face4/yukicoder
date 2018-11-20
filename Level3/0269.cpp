#include<iostream>
#include<cstring>
using namespace std;

static int dp[100][20001] = {};

int main(){
    const int mod = 1e9+7;
    int n, s, k;
    cin >> n >> s >> k;

    for(int j = 0; j <= s; j += n)   dp[0][j] = 1;

    for(int i = 1; i < n; i++){
        for(int j = 0; j <= s; j++){
            if(j >= k*(n-i))  dp[i][j] += dp[i-1][j-k*(n-i)];
            if(j >= (n-i))  dp[i][j] += dp[i][j-(n-i)];
            dp[i][j] %= mod;
        }
    }

    cout << dp[n-1][s] << endl;

    return 0;
}