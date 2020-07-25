#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

int main(){
    int n, q;
    cin >> n >> q;
    vector<pii> vp;
    for(int i = 0; i < n; i++){
        int x, w;
        cin >> x >> w;
        vp.push_back({x,w});
    }
    sort(vp.begin(), vp.end());
    vector<pii> ev;
    ev = vp;
    for(int i = 1; i <= q; i++){
        int x;
        cin >> x;
        ev.push_back({x, -i});
    }
    sort(ev.begin(), ev.end());
    int st = ev[0].first;
    ll tmp = 0, l = 0, r = 0;
    for(int i = 0; i < n; i++){
        tmp += (ll)(vp[i].first-st)*vp[i].second;
        r += vp[i].second;
    }
    vector<ll> ans(q+1);
    for(pii p : ev){
        int x = p.first, y = p.second;
        ll diff = x-st;
        tmp += diff*l - diff*r;
        if(y < 0){
            ans[-y] = tmp;
        }else{
            l += y;
            r -= y;
        }
        st = x;
    }
    for(int i = 1; i <= q; i++) cout << ans[i] << endl;
    return 0;
}