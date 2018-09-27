#include<iostream>
using namespace std;

const int INF = 1<<20;

int main(){
    int v[4];
    for(int i = 0; i < 4; i++)  cin >> v[i];

    int ans = 120;
    for(int i = 1; i <= 30; i++){
        for(int j = i+1; j <= 30; j++){
            for(int k = j+1; k <= 30; k++){
                int dp[31] = {};
                for(int l = 1; l < 31; l++) dp[l] = INF;
                for(int x = i; x <= 30; x++)    dp[x] = min(dp[x], dp[x-i]+1);
                for(int x = j; x <= 30; x++)    dp[x] = min(dp[x], dp[x-j]+1);
                for(int x = k; x <= 30; x++)    dp[x] = min(dp[x], dp[x-k]+1);

                int tmp = 0;
                for(int z = 0; z < 4; z++)  tmp += dp[v[z]];
                ans = min(ans, tmp);
            }
        }
    }

    cout << ans << endl;

    return 0;
}