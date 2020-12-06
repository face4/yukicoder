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
    ll n, m;
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        cout << modpow((n+1)/i, i-(n+1)%i-1)*modpow((n+1)/i+1, (n+1)%i)%mod*((n+1)/i-1)%mod << endl;
    }
    return 0;
}