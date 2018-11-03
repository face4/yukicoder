#include<iostream>
using namespace std;
typedef long long ll;

int main(){
    ll n;
    cin >> n;

    const ll mod = 1000000007;

    if(n >= mod){
        cout << 0 << endl;
        return 0;
    }

    ll ume[11] = {1, 927880474, 933245637, 668123525, 429277690, 733333339, 
                    724464507, 957939114, 203191898, 586445753, 698611116};

    ll x = 100000000;
    ll ans = ume[n/x];

    for(ll i = n/x*x+1; i <= n; i++){
        ans *= i;
        ans %= mod;
    }

    cout << ans << endl;

    return 0;
}