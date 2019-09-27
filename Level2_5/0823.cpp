#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;

const ll mod = 1000000007;
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
        if(k == 0)  return 1;
        if(n < k)   return 0;
        return (((po[n]*inv[n-k])%mod)*inv[k])%mod;
    }

    ll nPk(ll n, ll k){
        if(k == 0)  return 1;
        if(n < k)   return 0;
        return (po[n]*inv[n-k])%mod;
    }

    ll nHk(ll n, ll k){
        if(n == 0 && k == 0)    return 1;
        return nCk(n+k-1, k-1);
    }
};

int main(){
    ll n, k;
    cin >> n >> k;
    ModComb mc(n+1);
    ll a = (mc.nPk(n, k) - mc.nPk(n-1, k) + mod) % mod;
    ll b = mc.nCk(k, 2)*mc.nPk(n-2, k-2)%mod;
    ll c = (a-b+mod)%mod;
    ll ans = (n-1)*n%mod*modpow(2,mod-2)%mod * ((mc.nPk(n,k)-c+mod)%mod) % mod; 
    ans += n * mc.nPk(n-1, k) % mod;
    ans %= mod;
    cout << ans << endl;
    return 0;
}
