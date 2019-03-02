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
    cout << ((4*modpow(10,n)-1)%mod * modpow(3,mod-2))%mod << endl;
    return 0;
}