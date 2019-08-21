#include<iostream>
using namespace std;
typedef long long ll;

int main(){
    ll n, k;
    cin >> n >> k;
    ll ans = 0;
    for(ll i = 2; i*i <= k; i++){
        if(k%i) continue;
        if(k/i > 2*n)   continue;
        ll a = max(1ll, i-n);
        ll b = min(n, i-1);
        ll c = max(1ll, k/i-n);
        ll d = min(n, k/i-1);
        ll tmp = (b-a+1)*(d-c+1);
        if(i*i != k)    tmp *= 2;
        ans += tmp;
    }
    cout << ans << endl;
    return 0;
}