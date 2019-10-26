// 高速化
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<map>
#include<set>
using namespace std;

typedef long long ll;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, m, k, s, t;
    cin >> n >> m >> k >> s >> t;
    vector<pair<int,int>> sp;
    sp.push_back({1, s});
    sp.push_back({n, t});
    vector<int> a(m), b(m), c(m);
    for(int i = 0; i < m; i++){
        cin >> a[i] >> b[i] >> c[i];
        sp.push_back({a[i], b[i]});
        sp.push_back({a[i]+1, c[i]});
    }
    sort(sp.begin(), sp.end());
    sp.erase(unique(sp.begin(),sp.end()),sp.end());
    int siz = sp.size();
    auto p2id = [&](pair<int,int> p)->int{
        return lower_bound(sp.begin(),sp.end(), p)-sp.begin();
    };
    vector<pair<int,int>> vp[siz];
    auto bef = sp.begin(); int id = 1;
    for(auto it = ++sp.begin(); it != sp.end(); it++){
        if(it->first == bef->first){
            int diff = it->second-bef->second;
            vp[id].push_back({id-1, diff});
            vp[id-1].push_back({id, diff});
        }
        bef = it;
        id++;
    }
    for(int i = 0; i < m; i++){
        int ida = p2id({a[i], b[i]});
        int idb = p2id({a[i]+1, c[i]});
        vp[ida].push_back({idb, 0});
    }

    int from = p2id({1, s});
    int to = p2id({n, t});
    vector<ll> dp(siz, 1ll<<60);
    priority_queue<pair<ll,int>> pq;
    dp[from] = 0;
    pq.push({-0, from});
    while(!pq.empty()){
        auto p = pq.top();  pq.pop();
        ll cost = -p.first;
        int now = p.second;
        if(dp[now] != cost) continue;
        for(pair<int,int> edge : vp[now]){
            ll ncost = cost + edge.second;
            if(dp[edge.first] > ncost){
                dp[edge.first] = ncost;
                pq.push({-ncost, edge.first});
            }
        }
    }
    cout << (dp[to] == 1ll<<60 ? -1 : dp[to]) << endl;
    return 0;
}