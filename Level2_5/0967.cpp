// ?
#include<iostream>
#include<climits>
using namespace std;
typedef long long ll;

bool is(ll x, ll y, ll z){
    if(x == y || y == z || z == x || x <= 0 || y <= 0 || z <= 0)    return false;
    return (x-y)*(z-y) > 0;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        ll a, b, c, x, y, z;
        cin >> a >> b >> c >> x >> y >> z;
        if(a > c)   swap(a, c), swap(x, z);
        ll ans = LLONG_MAX;
        // make b biggest
        {
            ll aa = a, bb = b, cc = c;
            ll tmp = 0;
            if(aa >= bb) tmp += x*(aa-(bb-1)), aa = bb-1;
            if(cc >= bb) tmp += z*(cc-(bb-1)), cc = bb-1;
            if(aa == cc) tmp += min(x, z), aa--;
            if(is(aa,bb,cc))    ans = min(ans,tmp);
        }
        // make b smallest
        {
            ll aa = a, bb = b, cc = c;
            ll tmp = 0;
            if(aa == cc)   tmp += min(x, z), aa--;
            if(bb >= aa)   tmp += y*(bb-(aa-1)), bb = aa-1;
            if(is(aa,bb,cc))    ans = min(ans,tmp);
        }
        cout << (ans == LLONG_MAX ? -1 : ans) << endl;
    }
    return 0;
}