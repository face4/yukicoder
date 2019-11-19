#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;

vector<int> v[100001], depth(100001, 0), imos(100001, 0);
int par[20][100001] = {};
int n;

void dfs(int now, int p, int d){
    par[0][now] = p;
    depth[now] = d;
    for(int child : v[now]){
        if(child == p)  continue;
        dfs(child, now, d+1);
    }
}

void init(){
    dfs(0, -1, 0);
    for(int k = 0; k+1 < 20; k++){
        for(int i = 0; i <= n; i++){
            if(par[k][i] < 0)   par[k+1][i] = -1;
            else                par[k+1][i] = par[k][par[k][i]];
        }
    }
}

int lca(int u, int v){
    // make v depper
    if(depth[u] > depth[v]) swap(u, v);
    for(int k = 0; k < 20; k++){
        // uとvのdepthの差を2べきを使ってlogオーダーで縮める
        if(((depth[v]-depth[u])>>k)&1){
            v = par[k][v];
        }
    }
    if(u == v)  return u;
    // uとvのdepthは等しいのでこれからは一緒にdepthを弄る
    for(int k = 18; k >= 0; k--){
        if(par[k][u] != par[k][v]){
            u = par[k][u];
            v = par[k][v];
        }
    }
    return par[0][u];
}

ll ans;

void dfs2(int now, int p){
    for(int child : v[now]){
        if(child == p)  continue;
        dfs2(child, now);
        imos[now] += imos[child];
    }
    ans += (ll)imos[now]*(imos[now]+1)/2;
}

// editorialを読んだ　面白い
// id-0をsuper rootとする
int main(){
    cin >> n;
    v[0].push_back(1);
    for(int i = 0; i < n-1; i++){
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    init();
    int q;
    cin >> q;
    while(q-- > 0){
        int a, b;
        cin >> a >> b;
        int l = lca(a, b);
        imos[a]++, imos[b]++, imos[l]--, imos[par[0][l]]--;
    }
    ans = 0;
    dfs2(0, -1);
    cout << ans << endl;
    return 0;
}
