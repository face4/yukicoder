#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> p(n), a(n);
    for(int i = 0; i < n; i++){
        cin >> p[i] >> a[i];
    }
    vector<vector<int>> dp(2, vector<int>(n, 0));
    dp[0].back() = dp[1].back() = p[n-1];
    for(int i = n-2; i >= 0; i--){
        dp[0][i] = a[i]+max(dp[0][i+1]+a[i+1], dp[1][i+1]+p[i+1]);
        dp[1][i] = p[i]+max(dp[0][i+1], dp[1][i+1]);
    }
    cout << max(dp[0][0], dp[1][0]) << endl;
    return 0;
}