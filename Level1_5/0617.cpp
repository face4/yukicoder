#include<iostream>
#include<vector>

using namespace std;

int main(){
    int n , k;
    cin >> n >> k;
    vector<vector<bool> > dp(n+1, vector<bool>(k+1));

    for(int i = 0; i <= n; i++){
        dp[i][0] = true;
    }

    for(int i = 0; i <= n; i++){
        for(int j = 1; j <= k; j++){
           dp[i][j] = false;
        }
    }

    for(int i = 1; i <= n; i++){
        int a;
        cin >> a;
        for(int j = 0; j <= k; j++){
            if(dp[i-1][j] && (j + a) <= k){
                dp[i][j+a] = true;
            }
            if(dp[i-1][j]){
                dp[i][j] = true;
            }
        }
    }

    for(int i = k; i >= 0; i--){
        if(dp[n][i]){
            cout << i << endl;
            return 0;
        }
    }
}