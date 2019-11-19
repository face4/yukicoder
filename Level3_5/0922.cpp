#include<iostream>
#include<vector>
using namespace std;

struct UF{
    vector<int> p;
    int n;

    UF(int n) : n(n){
        p.resize(n);
        for(int i = 0; i < n; i++)  p[i] = i;
    }

    int parent(int x){
        if(p[x] != x)   p[x] = parent(p[x]);
        return p[x];
    }

    bool same(int x, int y){
        return parent(x)==parent(y);
    }

    void unite(int x, int y){
        x = parent(x), y = parent(y);
        if(x != y)  p[x] = y;
    }
};

vector<int> parents;
vector<int> v[100000], depth(100000, -1);
int n;
int par[20][100000];

void dfs(int now, int p, int d){
    par[0][now] = p;
    depth[now] = d;
    for(int child : v[now]){
        if(child == p)  continue;
        dfs(child, now, d+1);
    }
}

void init(){
    for(int i = 0; i < n; i++){
        if(depth[i] == -1)  parents.push_back(i), dfs(i, -1, 0);
    }
    for(int k = 0; k+1 < 20; k++){
        for(int i = 0; i < n; i++){
            if(par[k][i] < 0)   par[k+1][i] = -1;
            else                par[k+1][i] = par[k][par[k][i]];
        }
    }
}

int lca(int u, int v){
    if(depth[u] > depth[v]) swap(u, v);
    for(int k = 19; k >= 0; k--){
        if(((depth[v]-depth[u])>>k)&1){
            v = par[k][v];
        }
    }
    if(u == v)  return u;
    for(int k = 19; k >= 0; k--){
        if(par[k][u] != par[k][v]){
            u = par[k][u];
            v = par[k][v];
        }
    }
    return par[0][u];
}

typedef long long ll;
vector<int> query(100000, 0);
ll cost = 0;

int updateChildren(int now, int p){
    cost += depth[now]*query[now];
    for(int child : v[now]){
        if(child != p){
            query[now] += updateChildren(child, now);
        }
    }
    return query[now];
}

ll dfs3(ll c, int now, int p, int &queryN){
    ll ret = c;
    for(int child : v[now]){
        if(child != p){
            ret = min(ret, dfs3(c-query[child]+(queryN-query[child]), child, now, queryN));
        }
    }
    return ret;
}

ll dfs2(int now){
    ll tmp = 0;
    cost = 0;
    int x = updateChildren(now, -1);
    return dfs3(cost, now, -1, x);
}

int main(){
    int m, q;
    cin >> n >> m >> q;
    UF uf(n);
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        a--, b--;
        v[a].push_back(b);
        v[b].push_back(a);
        uf.unite(a, b);
    }
    init();
    ll ans = 0;
    while(q-- > 0){
        int a, b;
        cin >> a >> b;
        a--, b--;
        if(uf.same(a, b)){
            int l = lca(a, b);
            ans += depth[a]-depth[l] + depth[b]-depth[l];
        }else{
            query[a]++, query[b]++;
        }
    }
    for(int p : parents)    ans += dfs2(p);
    cout << ans << endl;
    return 0;
}