#include<iostream>
#include<vector>
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

int ans[50] = {};

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
                if(1 <= v && v <= 50 && 51 <= e.to && e.to <= 100){
                    ans[v-1] = e.to-51;
                }
                return d;
            }
        }
    }

    return 0;
}

const int INF = 1<<29;

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
    int n, hate;
    cin >> n;

    for(int i = 1; i <= n; i++){
        add_edge(0, i, 1);
        add_edge(50+i, 101, 1);
        
        cin >> hate;
        hate++;

        for(int j = 1; j <= n; j++){
            if(j == hate)   continue;
            add_edge(i, 50+j, 1);
        }
    }

    int num = max_flow(0, 101);

    if(num != n){
        cout << -1 << endl;
        return 0;
    }

    for(int i = 0; i < n; i++)  cout << ans[i] << endl;

    return 0;
}