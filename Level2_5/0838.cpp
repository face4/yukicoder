#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++)  cin >> v[i];
    sort(v.begin(), v.end());
    int ans = 0;
    if(n <= 3){
        ans = v.back()-v[0];
    }else{
        int INF = 2e9+1;
        vector<vector<int>> dp(2, vector<int>(n, INF));
        dp[0][1] = v[1]-v[0];
        dp[1][2] = v[2]-v[0];
        dp[0][3] = dp[0][1] + v[3]-v[2];
        for(int i = 4; i < n; i++){
            dp[0][i] = v[i]-v[i-1] + min(dp[0][i-2], dp[1][i-2]);
            dp[1][i] = v[i]-v[i-2] + min(dp[0][i-3], dp[1][i-3]);
        }
        ans = min(dp[0].back(), dp[1].back());
    }
    cout << ans << endl;
    return 0;
}
