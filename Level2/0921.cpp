#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++)  cin >> a[i];
    vector<vector<int>> dp(2, vector<int>(n, 0));
    dp[0][0] = dp[1][0] = 1;
    for(int i = 1; i < n; i++){
        dp[0][i] = max(dp[0][i-1], dp[1][i-1]);
        if(a[i] == a[i-1])  dp[1][i] = dp[1][i-1]+1;
        else if(i >= 2)     dp[1][i] = max(dp[1][i], dp[1][i-2]+1);
        dp[1][i] = max(dp[1][i], dp[0][i-1]);
    }
    cout << max(dp[0].back(), dp[1].back()) << endl;
    return 0;
}