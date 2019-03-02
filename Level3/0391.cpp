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

struct ModComb{
    vector<ll> po, inv;
    ll N;

    ModComb(ll n) : N(n), po(n), inv(n) {
        po[0] = 1;
        for(int i = 1; i < N; i++)  po[i] = (po[i-1] * i) % mod;
        inv[N-1] = modpow(po[N-1], mod-2, mod);
        for(int i = N-2; i >= 0; i--)   inv[i] = (inv[i+1] * (i+1)) % mod;
    }
    
    ll nCk(ll n, ll k){
        if(n < k)   return 0;
        return (((po[n]*inv[n-k])%mod)*inv[k])%mod;
    }

    ll nPk(ll n, ll k){
        if(n < k)   return 0;
        return (po[n]*inv[n-k])%mod;
    }

    ll nHk(ll n, ll k){
        if(n == 0 && k == 0)    return 1;
        return nCk(n+k-1, k);
    }
};

int main(){
    ll n, m;
    cin >> n >> m;
    
    if(n < m){
        cout << 0 << endl;
        return 0;
    }

    ModComb mc(100001);
    ll ans = modpow(m, n, mod);

    for(ll i = 1; i < m; i++){
        ans += (-2*(i%2)+1) * ((mc.nCk(m, i)*modpow(m-i, n, mod))%mod);
        if(ans < 0) ans += (-ans/mod+1)*mod;
        ans %= mod;
    }

    cout << ans << endl;

    return 0;
}