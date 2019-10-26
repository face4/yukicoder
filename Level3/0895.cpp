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

const ll mod = 1e9+7;

int main(){
    ll a, b, c, ans = 0;
    cin >> a >> b >> c;
    ll fa = 1, fb = 1, fc = (modpow(2, a+b+c-1)-1+mod)%mod;
    for(int i = 1; i <= c-1; i++){
        fa *= modpow(i, mod-2);
        fa %= mod;
        fa *= (a+b+c-2-i+1);
        fa %= mod;
    }
    for(int i = 1; i <= b-1; i++){
        fb *= modpow(i, mod-2);
        fb %= mod;
        fb *= (a+b-1-i+1);
        fb %= mod;
    }
    ll twoinv = modpow(2, mod-2);
    for(ll i = 1; i <= a; i++){
        fa = fa * modpow(a+b+c-2-i+1, mod-2) % mod * (a+b+c-2-i-(c-1)+1) % mod;
        fb = fb * modpow(a+b-1-i+1, mod-2) % mod * (a+b-1-i-(b-1)+1) % mod;
        fc = (fc-1+mod)*twoinv%mod;
        ans += fa*fb%mod*fc%mod;
        ans %= mod;
    }
    cout << ans << endl;
    return 0;
}