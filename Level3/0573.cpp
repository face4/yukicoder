#include<iostream>
#include<vector>
using namespace std;

typedef long long ll;
const ll mod = 1e9 + 7;

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
    vector<ll> fact(100001), inv(100001);
    fact[0] = 1;
    for(ll i = 1; i <= 100000; i++){
        fact[i] = (fact[i-1] * i)%mod;
    }
    inv[100000] = modpow(fact[100000], mod-2, mod);
    for(ll i = 99999; i >= 0; i--){
        inv[i] = (inv[i+1] * (i+1))%mod;
    }

    int n;
    cin >> n;

    auto ncm = [=](ll n, ll m) -> ll{
        return ((fact[n]*inv[m])%mod*inv[n-m])%mod;
    };

    ll ans = 0;
    for(int i = 1; i <= n; i++){
        ans += (ncm(n,i)*modpow(i, n-i, mod))%mod;
        ans %= mod;
    }

    cout << ans << endl;
    
    return 0;
}