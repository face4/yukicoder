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
        return (a%mod * modpow(a, b-1, p)) % p;
    }
}

int main(){
    ll n;
    cin >> n;

    if(n == 1){cout << 2 << endl; return 0;}
    
    // 4は{1,6,8,9}、5は{0,1,6,8,9}, 3は{0,1,8}
    ll ans = (4*modpow(5ll, (n-2)/2))%mod;
    if(n%2) ans = (ans * 3)%mod;

    cout << ans << endl;
    
    return 0;
}