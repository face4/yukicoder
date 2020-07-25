#include<iostream>
#include<vector>
using namespace std;

typedef long long ll;
ll mod = 1e9+7;

ll modpow(ll a, ll b, ll p = 1e9+7){
    if(b == 0)  return 1;

    if(b % 2 == 0){
        ll d = modpow(a, b/2, p);
        return (d*d) % p;
    }else{
        return (a%p * modpow(a, b-1, p)) % p;
    }
}

int main(){
    int n, k;
    cin >> n >> k;
    vector<ll> sum(n, 0);
    ll comb = 1, a = k, b = 1;
    sum[0] = 1;
    for(int i = 1; i < n; i++){
        comb *= a++;
        comb %= mod;
        comb *= modpow(b++, mod-2, mod);
        comb %= mod;
        sum[i] = (comb+sum[i-1])%mod;
    }
    ll ans = 0;
    for(int i = 0; i < n; i++){
        ll x;
        cin >> x;
        ans += x*sum[i]%mod*sum[n-1-i]%mod;
        ans %= mod;
    }
    cout << ans << endl;
    return 0;
}