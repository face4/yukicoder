#include<iostream>
#include<vector>
#include<numeric>
#include<cmath>
using namespace std;
typedef long long ll;

int gcd(int x, int y){
    if(x < y)   swap(x, y);
    if(y == 0)  return x;
    int cp = y;
    while((int)(log2(x)) > (int)(log2(y)))   y <<= 1;
    return gcd(cp, x^y);
}

int main(){
    int n;
    cin >> n;
    
    vector<int> v(n);
    for(int i = 0; i < n; i++)  cin >> v[i];

    ll ans = accumulate(v.begin(), v.end(), 0ll);

    vector<ll> d(100001, 0);
    for(int i = 0; i < n; i++){
        ll x = v[i];
        for(ll i = 1; i*i <= x; i++){
            if(x%i) continue;
            d[i] += x-x/i;
            if(i*i != x)    d[x/i] += x-i;
        }
    }

    int g = 0;
    for(int i = 0; i < n; i++)  g = gcd(g, v[i]);

    ll sub = 0;
    for(int i = 1; i < 1<<17; i++){
        ll make = 0;
        for(int j = 0; j < 17; j++){
            if((i>>j)&1)    make ^= (ll)g<<j;
        }
        if(make <= 100000) sub = max(sub, d[make]);
    }
    
    cout << ans-sub << endl;
    return 0;
}