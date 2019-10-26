#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    int n, m, k;
    cin >> n >> m >> k;
    int a[n][m];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
        }
    }
    vector<vector<bool>> dp(n+1, vector<bool>(k+1, 0));
    dp[0][0] = true;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            for(int x = k-a[i][j]; x >= 0; x--){
                dp[i+1][x+a[i][j]] = dp[i+1][x+a[i][j]]|dp[i][x];
            }
        }
    }
    for(int x = k; x >= 0; x--){
        if(dp[n][x]){
            cout << k-x << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}