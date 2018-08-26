#include<iostream>
#include<iomanip>
using namespace std;

#define fcout(x) cout << fixed << setprecision(x)

int main(){
    int n;
    cin >> n;

    static double dp[1000001][6] = {};

    dp[1][0] = 1.0;
    for(int i = 2; i <= n; i++){
        for(int j = 0; j < 6; j++){
            if(j == 0)  dp[i][j] = dp[i-1][j]/6;
            else        dp[i][j] = dp[i-1][j-1]*(6-j)/6 + dp[i-1][j]*(j+1)/6;
        }
    }

    fcout(10) << dp[n][5] << endl;

    return 0;
}