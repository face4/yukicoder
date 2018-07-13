#include<iostream>
using namespace std;

typedef long long ll;

ll mod = 1000000007;

int main(){
    ll n;
    cin >> n;

    ll ans = 1;
    for(ll i = 2*n; i >= 1; i--){
        ans *= i;
        if(i%2 == 0)    ans /= 2;
        ans %= mod;
    }

    cout << ans << endl;
    return 0;
}