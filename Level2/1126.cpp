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

const ll mod = 1000000007;

int main(){
    int n, m;
    cin >> n >> m;
    ll tmp = 1, ans = 0;
    for(int i = n; i <= m; i++){
        ans = (ans+tmp)%mod;
        tmp = tmp*modpow(i-n+1, mod-2, mod)%mod*(i+1)%mod;
    }
    cout << ans << endl;
    return 0;
}