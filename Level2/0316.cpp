#include<iostream>
using namespace std;

typedef long long ll;

ll gcd(ll a, ll b){
    return (b == 0 ? a : gcd(b, a%b));
}

ll lcm2(ll a, ll b){
    return a*b/gcd(a,b);
}

ll lcm3(ll a, ll b, ll c){
    return lcm2(lcm2(a,b), c);
}

int main(){
    ll n, a, b, c;
    cin >> n >> a >> b >> c;
    ll ans = n/a + n/b + n/c - n/lcm2(a,b) 
            - n/lcm2(b,c) - n/lcm2(c,a) + n/(lcm3(a,b,c));

    cout << ans << endl;
    return 0;
}