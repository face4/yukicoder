#include<iostream>
using namespace std;
typedef long long ll;

ll modpow(ll a, ll b, ll p = 1e9+7){
    if(b == 0)  return 1;

    if(b % 2 == 0){
        ll d = modpow(a, b/2, p);
        return (d*d) % p;
    }else{
        return (a%p * modpow(a, b-1, p)) % p;
    }
}

ll f(ll x, ll n, ll i){
    return (x + n-i) / n;
}

int main(){
    ll a, b, c;
    cin >> a >> b >> c;
    ll ans = 0;
    for(ll i = 1; i < c; i++){
        ans += f(a, c, i)%c*modpow(i, b, c)%c;
        ans %= c;
    }
    cout << ans << endl;
    return 0;
}