#include<iostream>
using namespace std;

typedef long long ll;

ll gcd(ll a, ll b){
    return b == 0 ? a : gcd(b, a%b);
}

int main(){
    ll t1, t2, t3;
    cin >> t1 >> t2 >> t3;
    ll a = t2-t1, b = t1*t2, c = t3-t2, d = t2*t3;
    ll g = gcd(a,b); a /= g; b /= g;
    g = gcd(c,d); c /= g; d /= g;
    cout << b*d/gcd(b,d) << "/" << gcd(a,c) << endl;
    return 0;
}