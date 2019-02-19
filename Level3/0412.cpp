#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;

int main(){
    int a[3], n;
    for(int i = 0; i < 3; i++)  cin >> a[i];
    sort(a, a+3);
    cin >> n;
    int e[n];
    for(int i = 0; i < n; i++)  cin >> e[i];
    sort(e, e+n);
    vector<ll> dp(4, 0);
    dp[0] = 1;
    for(int i = 0; i < n; i++){
        vector<ll> next = dp;
        for(int j = 0; j < 3; j++){
            if(e[i] >= a[j])    next[j+1] += dp[j];
            else                next[j] += dp[j];
        }
        next[3] += dp[3];
        dp = next;
    }
    cout << dp[3] << endl;
    return 0;
}