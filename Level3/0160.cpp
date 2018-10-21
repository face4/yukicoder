#include<iostream>
#include<vector>
#include<queue>
using namespace std;

typedef long long ll;
const int INF = 1ll<<30;

struct Edge{int to; int cost;};

int n, m, s, t, u, v, a, b;

// distは予めINF埋めされているものとする
void dijkstra(int from, vector<vector<Edge>> &path, int *dist){
    dist[from] = 0;
    priority_queue<pair<int, int>> pq;

    pq.push({dist[from], from});

    while(!pq.empty()){
        pair<int, int> now = pq.top();   pq.pop();
        int c = -now.first;
        int pos = now.second;
        if(c > dist[pos])    continue;
        for(Edge e : path[pos]){
            if(dist[e.to] > c + e.cost){
                dist[e.to] = c + e.cost;
                pq.push({-dist[e.to], e.to});
            }
        }
    }
}

int main(){
    int n, m, s, g;
    cin >> n >> m >> s >> g;

    vector<vector<Edge>> v(n);
    int a, b, c;
    for(int i = 0; i < m; i++){
        cin >> a >> b >> c;
        v[a].push_back(Edge({b,c}));
        v[b].push_back(Edge({a,c}));
    }

    int dist[n];
    for(int i = 0; i < n; i++)  dist[i] = INF;

    dijkstra(g, v, dist);

    vector<int> ans;
    int pos = s;
    ans.push_back(pos);

    while(pos != g){
        int next = n;
        for(Edge e : v[pos]){
            if(e.cost + dist[e.to] == dist[pos])  next = min(next, e.to);
        }
        pos = next;
        ans.push_back(pos);
    }

    for(int i = 0; i < ans.size(); i++) cout << ans[i] << " \n"[i == ans.size()-1];

    return 0;
}