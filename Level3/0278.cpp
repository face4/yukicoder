#include<iostream>
using namespace std;

typedef long long ll;

int main(){
    ll n;
    cin >> n;

    if(n % 2 == 0)  n /= 2;

    ll ans = 0;
    for(ll i = 1; i*i <= n; i++){
        if(n % i != 0)  continue;
        ans += i + n/i;
        if(i == n/i)    ans -= i;
    }

    cout << ans << endl;
    
    return 0;
}