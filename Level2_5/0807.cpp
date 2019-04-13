#include<iostream>
#include<vector>
#include<queue>
using namespace std;
typedef long long ll;
const ll INF = 1ll<<60;

int main(){
    int n, m;
    cin >> n >> m;
    vector<pair<int,int>> v[n];
    int a, b, c;
    for(int i = 0; i < m; i++){
        cin >> a >> b >> c;
        a--, b--;
        v[a].push_back({b, c});
        v[b].push_back({a, c});
    }
    vector<vector<ll>> d(2, vector<ll>(n, INF));
    priority_queue<pair<ll, pair<int, int>>> pq;
    pq.push({-0, {0, 0}});
    while(!pq.empty()){
        auto p = pq.top();  pq.pop();
        ll cost = -p.first;
        int pos = p.second.first, used = p.second.second;
        if(d[used][pos] <= cost)    continue;
        d[used][pos] = cost;
        for(pair<int,int> path : v[pos]){
            ll ncost = cost + path.second;
            int next = path.first;
            if(d[used][next] > ncost)   pq.push({-ncost, {next, used}});
            if(used == 0 && d[1][next] > cost)  pq.push({-cost, {next, 1}});
        }
    }
    cout << 0 << endl;
    for(int i = 1; i < n; i++){
        cout << d[1][i]+d[0][i] << endl;
    }
    return 0;
}