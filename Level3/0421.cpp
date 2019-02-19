#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

struct edge{
    int to, cap, rev;
};

#define MAX_V 3000
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

int di[8] = {0,0,1,-1,1,1,-1,-1};
int dj[8] = {1,-1,0,0,1,-1,1,-1};
#define inRange(x,a,b) (a <= x && x < b)

int main(){
    int n, m;
    cin >> n >> m;
    int SOURCE = 2900, SINK = 2901;

    auto enc = [=](int i, int j) -> int{
        return i*m + j;
    };

    int black = 0, white = 0;
    char mat[n][m];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> mat[i][j];
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(mat[i][j] == '.')    continue;
            if(mat[i][j] == 'w'){
                white++;
                add_edge(enc(i,j), SINK, 1);
                continue;
            }
            black++;
            add_edge(SOURCE, enc(i,j), 1);
            for(int k = 0; k < 4; k++){
                int ni = i+di[k], nj = j+dj[k];
                if(inRange(ni,0,n)&&inRange(nj,0,m)&&mat[ni][nj]=='w'){
                    add_edge(enc(i,j), enc(ni,nj), 1);
                }
            }
        }
    }

    int t = max_flow(SOURCE, SINK);
    black -= t, white -= t;
    int p = min(black, white);

    cout << 100*t + 10*p + max(black,white)-p << endl;

    return 0;
}