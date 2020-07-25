#include<iostream>
#include<vector>
using namespace std;

int dp[300][301][301] = {}; // MLE?
const int mod = 1000000007;

int main(){
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> p(m), q(m), c(m);
    while(m--){
        cin >> p[m] >> q[m] >> c[m];
    }
    for(int j = 1; j <= 300; j++)   dp[0][j][0] = 1;
    for(int i = 0; i+1 < n; i++){
        for(int j = 0; j < p.size(); j++){
            for(int x = 0; x+c[j] <= k; x++){
                (dp[i+1][q[j]][x+c[j]] += dp[i][p[j]][x]) %= mod;
            }
        }
    }
    int ans = 0;
    for(int j = 1; j <= 300; j++)   (ans += dp[n-1][j][k]) %= mod;
    cout << ans << endl;
    return 0;
}