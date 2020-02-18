// ?
#include<iostream>
#include<climits>
using namespace std;
typedef long long ll;

bool is(ll x, ll y, ll z){
    if(x == y || y == z || z == x || x <= 0 || y <= 0 || z <= 0)    return false;
    return (x-y)*(z-y) > 0;
}


// 2 1 3 or 3 1 2
void f(ll &ans, ll a, ll b, ll c, ll x, ll y, ll z){
    ll step = max(0ll, max(c-(b-1), a-(b-1)));
    ll tmp = step*z;
    a -= step, c -= step;
    if(a == c){
        if(a == b-1)    a--, c--, tmp += z;
        tmp += min(x, y);
        a--, b--;
    }
    if(is(a,b,c))   ans = min(ans, tmp);
}

// 1 3 2
void g(ll &ans, ll a, ll b, ll c, ll x, ll y, ll z){
    ll tmp = 0;
    if(a <= b){
        ll step = b-(a-1);
        tmp += step*y;
        b -= step, c -= step;
    }
    if(c <= b){
        ll step = b-(c-1);
        tmp += step*x;
        b -= step, a -= step;
    }
    if(a == c){
        a--, b--;
        tmp += min(x, y);
    }
    if(is(a,b,c))   ans = min(ans, tmp);
}

int main(){
    ll a, b, c, x, y, z;
    int t;
    cin >> t;
    while(t--){
        cin >> a >> b >> c >> x >> y >> z;
        ll ans = LLONG_MAX;
        f(ans,a,b,c,x,y,z);
        g(ans,a,b,c,x,y,z);
        cout << (ans == LLONG_MAX ? -1 : ans) << endl;
    }
    return 0;
}