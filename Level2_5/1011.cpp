#include<iostream>
#include<vector>
using namespace std;

typedef long long ll;
ll mod = 1e9+7;

int main(){
    int n, d, k;
    cin >> n >> d >> k;
    vector<ll> dp(k+1, 0), ndp(k+1, 0);
    dp[0] = 1;
    while(n--){
        fill(ndp.begin(), ndp.end(), 0);
        for(int i = 0; i < k; i++){
            (ndp[i+1] += dp[i]) %= mod;
            if(i+1+d <= k)    (ndp[i+1+d] += (mod-dp[i])) %= mod;
        }
        for(int i = 1; i <= k; i++)   (ndp[i] += ndp[i-1]+mod) %= mod;
        swap(dp, ndp);
    }
    cout << dp[k] << endl;
    return 0;
}