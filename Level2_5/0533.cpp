#include<iostream>
using namespace std;

typedef long long ll;
const ll mod = 1000000007;

int main(){
    int n;
    cin >> n;

    static ll dp[4][1000005] = {};

    dp[1][1] = 1;
    dp[2][2] = 1;
    dp[3][3] = 1;

    for(int j = 1; j <= n; j++){
        for(int i = 1; i <= 3; i++) dp[i][j] %= mod;
        for(int i = 1; i <= 3; i++){
            for(int k = 1; k <= 3; k++){
                if(i == k)  continue;
                dp[k][j+k] += dp[i][j];
            }
        }
    }

    cout << (dp[1][n] + dp[2][n] + dp[3][n]) % mod << endl;

    return 0;
}