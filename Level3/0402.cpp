#include<iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int h, w;
    cin >> h >> w;

    int dp[h][w];
    string s;
    
    for(int i = 0; i < h; i++){
        cin >> s;
        for(int j = 0; j < w; j++){
            dp[i][j] = (s[j] == '#');
        }
    }

    int ans = 1;
    for(int i = 1; i < h; i++){
        for(int j = 1; j < w; j++){
            if(dp[i][j] == 0)    continue;
            dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1])) + 1;
            ans = max(ans, dp[i][j]);
        }
    }

    cout << (ans+1)/2 << endl;
    
    return 0;
}