#include<iostream>
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

int main(){
    int t;
    cin >> t;
    while(t--){
        ll n, a[3], b[3];
        cin >> n;
        for(int i = 0; i < 3; i++)  cin >> a[i] >> b[i], a[i] = a[i]*modpow(b[i],mod-2)%mod;
        ll ans = 0;
        for(int i = 0; i < 3; i++)  (ans += modpow(a[i]+a[(i+1)%3], n)-modpow(a[i], n)-modpow(a[(i+1)%3], n)+mod+mod) %= mod;
        cout << (1-ans+mod)%mod << endl;
    }
    return 0;
}