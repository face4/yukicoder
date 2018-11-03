#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;

typedef long long ll;

int main(){
    int n;
    ll d, t;
    cin >> n >> d >> t;
    
    // modulo, val
    map<ll, vector<ll>> m;
    map<ll, vector<pair<ll,ll>>> seg;

    ll x[n];
    for(int i = 0; i < n; i++)  cin >> x[i];
    sort(x, x+n);

    for(int i = 0; i < n; i++){
        ll modulo;
        if(x[i] < 0)   modulo = d - (abs(x[i])%d);
        else           modulo = x[i]%d;
        m[modulo].push_back(x[i]);
    }
    
    for(auto p : m){
        for(ll l : p.second){
            seg[p.first].push_back({l-t*d, l+t*d});
        }
    }

    for(auto p : seg){
        auto it = seg[p.first].begin();
        while(it != seg[p.first].end()){
            auto next = it;
            next++;
            
            if(next == seg[p.first].end())  break;

            if((*it).second >= (*next).first){
                (*it).second = (*next).second;
                seg[p.first].erase(next);
            }else{
                it++;
            }

        }
    }

    ll ans = 0;
    for(auto p : seg){
        for(auto q : p.second)  ans += (q.second-q.first)/d + 1;
    }

    cout << ans << endl;
    
    return 0;
}