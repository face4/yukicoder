#include<iostream>
using namespace std;

typedef long long ll;
const ll mod = 129402307;

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
    string s, t;
    cin >> s >> t;

    if(t == "0"){
        cout << 1 << endl;
        return 0;
    }

    ll n = 0, m = 0;
    for(int i = 0; i < s.length(); i++){
        n = n*10 + s[i]-'0';
        n %= mod;
    }

    for(int i = 0; i < t.length(); i++){
        m = m*10 + t[i]-'0';
        m %= (mod-1);
    }

    ll ans = modpow(n, m, mod);
    if(n == 0)  ans = 0;
    cout << ans << endl;

    return 0;
}