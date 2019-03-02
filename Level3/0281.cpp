#include<iostream>
using namespace std;
typedef long long ll;

bool isK(ll a, ll b, ll c){
    return (b-a)*(b-c) > 0 && a != b && b != c && c != a;
}

int main(){
    ll d, a, b, c;
    cin >> d >> a >> b >> c;
    
    if(isK(a, b, c)){
        cout << 0 << endl;
        return 0;
    }else if(d == 0){
        cout << -1 << endl;
        return 0;
    }

    bool flag = false;
    ll ans = 1ll<<60;
    if(a == c)  a = max(0ll, a-d), flag = true;

    // make b longest
    ll aa = a, bb = b, cc = c, score = 0;
    if(aa >= bb){
        score += (aa-bb+1+d-1)/d;
        aa -= (aa-bb+1+d-1)/d*d;
        if(aa < 0)  aa = 0;
    }
    if(cc >= bb){
        score += (cc-bb+1+d-1)/d;
        cc -= (cc-bb+1+d-1)/d*d;
        if(cc < 0)  cc = 0;
    }
    if(isK(aa, bb, cc)){
        ans = min(ans, score+flag);
    }

    // make b shortest
    aa = a, bb = b, cc = c, score = 0;
    ll t = min(aa, cc);
    if(bb >= t){
        score += (bb-t+1+d-1)/d;
        bb -= (bb-t+1+d-1)/d*d;
        if(bb < 0)  bb = 0;
    }
    if(isK(aa, bb, cc)){
        ans = min(ans, score+flag);
    }

    if(ans == (1ll<<60)){
        cout << -1 << endl;
    }else{
        cout << ans << endl;
    }

    return 0;
}