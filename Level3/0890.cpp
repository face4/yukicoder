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

ll gcd(ll a, ll b){
    return b == 0 ? a : gcd(b, a%b);
}

int main(){
    ll n, k;
    cin >> n >> k;
    vector<int> v;
    ll x = gcd(n, k);
    for(int i = 2; i*i <= x; i++){
        if(x%i == 0){
            v.push_back(i);
            while(x%i == 0) x /= i;
        }
    }
    if(x != 1)  v.push_back(x);
    ModComb mc(n+1);
    int siz = v.size();
    ll ans = 0;
    for(int i = 1; i < 1<<siz; i++){
        int tmp = 1, cnt = 0;
        for(int j = 0; j < siz; j++){
            if((i>>j)&1)    tmp *= v[j], cnt++;
        }
        ll x = cnt%2 == 0 ? -1 : 1;
        x *= mc.nCk(n/tmp, k/tmp);
        x = (x + mod) % mod;
        ans += x;
        ans %= mod;
    }
    cout << ans << endl;
    return 0;
}