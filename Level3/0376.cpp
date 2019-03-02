#include<iostream>
#include<cmath>
using namespace std;
typedef long long ll;

int main(){
    ll n;
    cin >> n;

    ll ans = n;
    for(ll i = 1; i*i*i <= n; i++){
        if(n%i) continue;
        for(ll j = (ll)sqrt(n/i); j >= 1; j--){
            if((n/i)%j)    continue;
            ans = min(ans, i-1+j-1+(n/i/j)-1);
            break;
        }
    }

    cout << ans << " " << n-1 << endl;

    return 0;
}