#include<iostream>
using namespace std;

typedef long long ll;
const ll mod = 1000000007;

ll fact(ll x){
    ll ret = 1;
    while(x > 1){
        ret *= x--;
        ret %= mod;
    }
    return ret;
}

int main(){
    ll n;
    cin >> n;

    ll ans = (fact(n)*fact(n))%mod;
    n = 2*n-1;
    
    while(n > 1){
        ans *= n;
        ans %= mod;
        n -= 2;
    }

    cout << ans << endl;

    return 0;
}