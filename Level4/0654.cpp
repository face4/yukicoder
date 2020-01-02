#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;

struct edge{
    int to;
    ll cap;
    int rev;
};

#define MAX_V 5000
vector<edge> G[MAX_V];
bool used[MAX_V];

void add_edge(int from, int to, ll cap){
    G[from].push_back((edge){to, cap, (int)G[to].size()});
    G[to].push_back((edge){from, 0, (int)G[from].size()-1});
}

// v...target vertex, t...end vertex, f...maximum flow 
ll dfs(int v, int t, ll f){
    if(v == t)  return f;

    used[v] = true;
    for(int i = 0; i < G[v].size(); i++){
        edge &e = G[v][i];
        if(!used[e.to] && e.cap > 0){
            ll d = dfs(e.to, t, min(f, e.cap));
            if(d > 0){
                e.cap -= d;
                G[e.to][e.rev].cap += d;
                return d;
            }
        }
    }

    return 0;
}

const ll INF = 1ll<<60;

// maxflow from s to t
ll max_flow(int s, int t){
    ll flow = 0;
    while(1){
        memset(used, 0, sizeof(used));
        ll f = dfs(s, t, INF);
        if(f == 0)  return flow;
        flow += f;
    }
}

typedef pair<int,int> pii;

int main(){
    int n, m, d;
    cin >> n >> m >> d;
    vector<int> tim[n], u(m), v(m), p(m), q(m), w(m);
    tim[0].push_back(0);
    tim[n-1].push_back(1e9);
    for(int i = 0; i < m; i++){
        cin >> u[i] >> v[i] >> p[i] >> q[i] >> w[i];
        u[i]--, v[i]--;
        q[i] += (v[i]==n-1 ? 0 : d);
        if(q[i] > 1e9)  continue;
        tim[u[i]].push_back(p[i]);
        tim[v[i]].push_back(q[i]);
    }
    vector<pii> vp;
    for(int i = 0; i < n; i++){
        if(tim[i].size() == 0)  continue;
        sort(tim[i].begin(), tim[i].end());
        tim[i].erase(unique(tim[i].begin(),tim[i].end()),tim[i].end());
        for(int j : tim[i]){
            vp.push_back({i, j});
        }
    }
    auto f = [&](int i, int j)->int{
        return lower_bound(vp.begin(),vp.end(),make_pair(i,j))-vp.begin();
    };
    // 待機
    for(int i = 0; i < n; i++){
        for(int j = 0; j+1 < tim[i].size(); j++){
            add_edge(f(i,tim[i][j]), f(i,tim[i][j+1]), INF);
        }
    }
    // 移動
    for(int i = 0; i < m; i++){
        if(q[i] > 1e9)  continue;
        add_edge(f(u[i], p[i]), f(v[i], q[i]), w[i]);
    }
    cout << max_flow(f(0, 0), f(n-1, 1e9)) << endl;
    return 0;
}