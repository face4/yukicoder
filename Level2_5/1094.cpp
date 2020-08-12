#include<iostream>
#include<vector>
using namespace std;

typedef pair<int,int> pii;

struct LCA{
    int n, bit; // n < 1<<bit
    vector<int> depth;
    vector<vector<int>> par, v;

    LCA(int n) : n(n){
        depth.resize(n, -1);
        bit = 0;
        while(1<<bit <= n)  bit++;
        par.resize(bit);
        for(int i = 0; i < bit; i++)    par[i].resize(n);
        v.resize(n);
    }

    void add_edge(int a, int b){
        v[a].push_back(b);
        v[b].push_back(a);
    }

    void dfs(int now, int p, int d){
        par[0][now] = p;
        depth[now] = d;
        for(int child : v[now]){
            if(child == p)  continue;
            dfs(child, now, d+1);
        }
    }

    void build(){
        for(int i = 0; i < n; i++){
            if(depth[i] == -1)    dfs(i, -1, 0);
        }
        for(int k = 0; k+1 < bit; k++){
            for(int i = 0; i < n; i++){
                if(par[k][i] < 0)   par[k+1][i] = -1;
                else                par[k+1][i] = par[k][par[k][i]];
            }
        }
    }

    int lca(int a, int b){
        // make b deeper
        if(depth[a] > depth[b]) swap(a, b);
        for(int k = 0; k < 30; k++){
            // depth(b)-depth(a) is equal to or bigger than 2^k
            if(((depth[b]-depth[a])>>k)&1){
                b = par[k][b];
            }
        }
        if(a == b)  return a;
        for(int k = bit-1; k >= 0; k--){
            if(par[k][a] != par[k][b]){
                a = par[k][a];
                b = par[k][b];
            }
        }
        return par[0][a];
    }

    int dist(int a, int b){
        int l = lca(a, b);
        return depth[a]-depth[l] + depth[b]-depth[l];
    }
};

vector<pii> v[200000];
vector<int> ind(200000), val;
int k = 0;

void dfs(int x, int p){
    ind[x] = k;
    for(pii edge : v[x]){
        int to = edge.first, cost = edge.second;
        if(to == p) continue;
        val.push_back(cost);    k++;
        dfs(to, x);
        val.push_back(-cost);   k++;
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    LCA l(n);
    for(int i = 0; i < n-1; i++){
        int a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        v[a].push_back({b, c});
        v[b].push_back({a, c});
        l.add_edge(a, b);
    }
    l.build();
    val.push_back(0);
    dfs(0, -1);
    for(int i = 1; i < val.size(); i++) val[i] += val[i-1];
    int q;
    cin >> q;
    while(q--){
        int s, t;
        cin >> s >> t;
        s--, t--;
        int lca = l.lca(s, t);
        cout << val[ind[s]]-val[ind[lca]] + val[ind[t]]-val[ind[lca]] << endl;
    }
    return 0;
}