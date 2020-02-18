#include<iostream>
using namespace std;
typedef long long ll;
const int mod = 1000000007;

int main(){
    ll n, p;
    cin >> n >> p;
    ll fib[3];
    fib[0] = 0;
    fib[1] = 1;
    if(n == 1){
        cout << 0 << endl;
        return 0;
    }else if(n == 2){
        cout << 1 << endl;
        return 0;
    }
    ll ans = 1, his = 1;
    for(int i = 2; i < n; i++){
        fib[2] = (fib[1]*p+fib[0])%mod;
        (his += fib[2]) %= mod;
        (ans += fib[2]*his%mod) %= mod;
        for(int j = 0; j < 2; j++)  fib[j] = fib[j+1];
    }
    cout << ans << endl;
    return 0;
}