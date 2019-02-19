#include<iostream>
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

int main(){
    ll n;
    cin >> n;

    ll a = modpow(100, n-1, mod);
    cout << (a + (a-1+mod)%mod * modpow(99, mod-2, mod))%mod << endl;

    for(int i = 0; i < (n%11)-1; i++)   cout << "10";
    cout << (n%11-1 >= 0) << endl;

    return 0;
}