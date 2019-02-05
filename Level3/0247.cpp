#include<iostream>
using namespace std;

const int INF = 1e9;

int main(){
    int c, n, a;
    cin >> c >> n;

    int dp[c+1];
    fill(dp, dp+c+1, INF);

    dp[0] = 0;
    for(int i = 0; i < n; i++){
        cin >> a;
        for(int j = 0; j <= c-a; j++){
            if(dp[j] == INF)    continue;
            dp[j+a] = min(dp[j+a], dp[j]+1);
        }
    }

    cout << (dp[c] == 1e9 ? -1 : dp[c]) << endl;

    return 0;
}