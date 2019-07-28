#include<iostream>
#include<vector>
#include<queue>
using namespace std;
typedef long long ll;

// (N+M)log(N) + N^2 ?
int main(){
    int n, m, p, q, t;
    cin >> n >> m >> p >> q >> t;
    p--, q--;
    vector<pair<int,int>> v[n];
    while(m-- > 0){
        int a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        v[a].push_back({b, c});
        v[b].push_back({a, c});
    }
    const ll INF = 1ll<<60;
    vector<ll> O(n, INF), P(n, INF), Q(n, INF);
    O[0] = P[p] = Q[q] = 0;
    priority_queue<pair<ll,int>> pq;
    
    pq.push({-0, 0});
    while(!pq.empty()){
        auto x = pq.top();  pq.pop();
        for(auto next : v[x.second]){
            ll nc = -x.first + next.second;
            if(nc < O[next.first]){
                O[next.first] = nc;
                pq.push({-nc, next.first});
            }
        }
    }
    pq.push({-0, p});
    while(!pq.empty()){
        auto x = pq.top();  pq.pop();
        for(auto next : v[x.second]){
            ll nc = -x.first + next.second;
            if(nc < P[next.first]){
                P[next.first] = nc;
                pq.push({-nc, next.first});
            }
        }
    }
    pq.push({-0, q});
    while(!pq.empty()){
        auto x = pq.top();  pq.pop();
        for(auto next : v[x.second]){
            ll nc = -x.first + next.second;
            if(nc < Q[next.first]){
                Q[next.first] = nc;
                pq.push({-nc, next.first});
            }
        }
    }

    if(2*O[p] > t || 2*O[q] > t){
        cout << -1 << endl;
        return 0;
    }

    ll ans = 0;
    if(O[p] + O[q] + P[q] <= t){
        ans = t;
    }

    for(int i = 0; i < n; i++){ // where the two separates
        for(int j = 0; j < n; j++){ // where the two meets
            ll tmp = O[i] + max(P[i] + P[j], Q[i] + Q[j]) + O[j];
            if(tmp <= t){
                ans = max(ans, t-tmp + O[i] + O[j]);
            }
        }
    }

    cout << ans << endl;

    return 0;
}