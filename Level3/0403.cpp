#include<iostream>
using namespace std;

typedef long long ll;
const ll mod = 1e9+7;

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
    ll a, b, c;
    scanf("%lld^%lld^%lld", &a, &b, &c);

    a %= mod;

    ll ansa = modpow(modpow(a, b), c);
    ll ansb = modpow(a, modpow(b, c, mod-1));

    // b, cは非零なので、aが1e9+7の倍数であった場合は必ず0になる.
    if(a == 0)  ansa = ansb = 0;

    cout << ansa << " " << ansb << endl;

    return 0;
}