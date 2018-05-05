#include<iostream>
#include<cmath>
using namespace std;

typedef long long ll;

int main(){
    ll x;
    cin >> x;
    ll ans = 1;
   
    for(ll i = 2; i*i <= x; i++){
        ll cnt = 0;
        while(x%i == 0){
            x /= i;
            cnt++;
        }

        if(cnt%2 == 1){
            ans *= i;
        }
    }

    if(x > 1)   ans *= x;
    
    cout << ans << endl;
    return 0;
}