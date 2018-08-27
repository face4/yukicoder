// mod本当にめんどくさい
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

    b %= mod;

    if(c == 1){
        cout << (b*(d%mod))%mod << endl;
        return 0;
    }

    ll ans = ( (modpow(c,d,mod)%mod *( ((c-1)%mod*b+b)%mod)%mod +mod-b )%mod * modpow(c-1,mod-2,mod)%mod + mod - b)%mod;
    
    cout << ans << endl;
    return 0;
}