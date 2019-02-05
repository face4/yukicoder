#include<iostream>
#include<vector>
#include<set>
#include<cstring>
using namespace std;
struct edge{
    int to, cap, rev;
};

#define MAX_V 102
vector<edge> G[MAX_V];
bool used[MAX_V];

void add_edge(int from, int to, int cap){
    G[from].push_back((edge){to, cap, (int)G[to].size()});
    G[to].push_back((edge){from, 0, (int)G[from].size()-1});
}

// v...target vertex, t...end vertex, f...maximum flow 
int dfs(int v, int t, int f){
    if(v == t)  return f;

    used[v] = true;
    for(int i = 0; i < G[v].size(); i++){
        edge &e = G[v][i];
        if(!used[e.to] && e.cap > 0){
            int d = dfs(e.to, t, min(f, e.cap));
            if(d > 0){
                e.cap -= d;
                G[e.to][e.rev].cap += d;
                return d;
            }
        }
    }

    return 0;
}

const int INF = 1<<29;

// maxflow from s to t
int max_flow(int s, int t){
    int flow = 0;
    while(1){
        memset(used, 0, sizeof(used));
        int f = dfs(s, t, INF);
        if(f == 0)  return flow;
        flow += f;
    }
}

int main(){
    int w, n, m, c, q, x;
    cin >> w >> n;

    int SINK = 0, DEST = 101;

    vector<int> J(n);
    for(int i = 0; i < n; i++){
        cin >> J[i];
        add_edge(SINK, i+1, J[i]);
    }

    cin >> m;
    for(int i = 0; i < m; i++){
        cin >> c;
        add_edge(51+i, DEST, c);
    }

    for(int i = 0; i < m; i++){
        set<int> no;
        cin >> q;
        while(q-- > 0){
            cin >> x;
            no.insert(x);
        }
        for(int j = 1; j <= n; j++){
            if(no.count(j) == 0)    add_edge(j, 51+i, J[j-1]);
        }
    }

    cout << (max_flow(SINK, DEST) >= w ? "SHIROBAKO" : "BANSAKUTSUKITA") << endl;

    return 0;
}