#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;

int main(){
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> l(m), r(m);
    for(int i = 0; i < m; i++)  cin >> l[i] >> r[i], l[i]--, r[i]--;
    vector<ll> dp(n+1, 1);
    auto f = [&](int i)->ll{
        if(i < 0)   return 0;
        return dp[i];
    };
    for(int i = 0; i < k; i++){
        vector<ll> next(n+1, 0);
        for(int j = 0; j < m; j++){
            ll val = (f(r[j])-f(l[j]-1)+mod)%mod;
            next[l[j]] = (next[l[j]]+val)%mod;
            next[r[j]+1] = (next[r[j]+1]-val+mod)%mod;
        }
        // imos
        for(int j = 0; j < n; j++)  next[j+1] += next[j], next[j+1] %= mod;
        // cumulative sum
        for(int j = 0; j < n; j++)  next[j+1] += next[j], next[j+1] %= mod;
        dp = next;
    }
    cout << (dp[n-1]-dp[n-2]+mod)%mod << endl;
    return 0;
}