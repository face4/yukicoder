#include<iostream>
using namespace std;

typedef long long ll;
const ll mod = 1000000007;

// a^b mod p を計算する
ll modpow(ll a, ll b, ll p){
    if(b == 0)  return 1;

    if(b % 2 == 0){
        ll d = modpow(a, b/2, p);
        return (d*d) % p;
    }else{
        return (a%p * modpow(a, b-1, p)) % p;
    }
}

int main(){
    ll b, c, d;
    cin >> b >> c >> d;

    if(c%mod == 1){
        cout << (b%mod)*(d%mod)%mod << endl;
        return 0;
    }

    ll f = (b%mod)*(c%mod)%mod;

    ll alpha = (mod-f) % mod * modpow((c-1)%mod, mod-2, mod) % mod;

    ll ans = ((f-alpha+mod)%mod * modpow(c%mod, d-1, mod) % mod + alpha) % mod;

    cout << ans%mod << endl;

    return 0;
}