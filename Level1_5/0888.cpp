#include<iostream>
using namespace std;
typedef long long ll;

int main(){
    ll n;
    cin >> n;
    ll ans = 0;
    for(ll i = 1; i*i <= n; i++){
        if(n%i) continue;
        ans += i + n/i;
        if(n/i == i)    ans -= i;
    }
    cout << ans << endl;
    return 0;
}