// ?
#include<iostream>
using namespace std;
typedef long long ll;

bool is(ll x, ll y, ll z){
    if(x <= 0 || y <= 0 || z <= 0)  return false;
    if(x == y || y == z || z == x)  return false;
    return (x-y)*(z-y)>0;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        ll a, b, c;
        cin >> a >> b >> c;
        if(is(a,b,c)){
            cout << 0 << endl;
            continue;
        }
        if(a > c)   swap(a, c);
        ll ans = 1ll<<60;
        // make b biggest
        {
            ll aa = a, bb = b, cc = c;
            ll tmp = 0;
            if(aa >= bb) tmp += aa-(bb-1), aa = bb-1;
            if(cc >= bb) tmp += cc-(bb-1), cc = bb-1;
            if(aa == cc)    tmp++, aa--;
            if(is(aa,bb,cc))    ans = min(ans,tmp);
        }
        // make b smallest
        {
            ll aa = a, bb = b, cc = c;
            ll tmp = 0;
            if(aa == cc)    aa--, tmp++;
            if(bb >= aa)   tmp += bb-(aa-1), bb = aa-1;
            if(is(aa,bb,cc))    ans = min(ans,tmp);
        }
        cout << (ans == 1ll<<60 ? -1 : ans) << endl;
    }
    return 0;
}