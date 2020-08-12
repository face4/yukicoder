#include<iostream>
using namespace std;

typedef long long ll;

ll modpow(ll a, ll b, ll p = 1e9+7){
    if(b == 0)  return 1;

    if(b % 2 == 0){
        ll d = modpow(a, b/2, p);
        return (d*d) % p;
    }else{
        return (a%p * modpow(a, b-1, p)) % p;
    }
}

int main(){
    int p, n;
    cin >> p >> n;
    int a[n];
    for(int i = 0; i < n; i++)  cin >> a[i];
    ll ans = a[0];
    for(int i = 1; i < n; i++){
        char c;
        cin >> c;
        if(c == '+')    (ans += a[i]) %= p;
        if(c == '-')    (ans += p-a[i]) %= p;
        if(c == '*')    (ans *= a[i]) %= p;
        if(c == '/')    (ans *= modpow(a[i], p-2, p)) %= p;
    }
    cout << ans << endl;
    return 0;
}