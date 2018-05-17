#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
typedef long long ll;
#define MOD 1000000000000

int main(){
    ll n;
    cin >> n;
    if(n >= 50) cout << "000000000000" << endl;
    else{
        ll ans = 1;
        bool overflow = false;
        for(ll i = n; i >= 2; i--){
            ans *= i;
            if(ans > MOD){
                ans %= MOD;
                overflow = true;
            }
        }

        if(overflow)    cout << setw(12) << setfill('0') << ans << endl;
        else            cout << ans << endl;
    }

    return 0;
}