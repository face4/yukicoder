#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;

vector<int> edge[100000], tax(100000), atax(100000);
int parent[20][100000];
int depth[100000];

void dfs(int v, int p, int d){
    parent[0][v] = p;
    depth[v] = d;
    atax[v] = (p == -1 ? 0 : atax[p]) + tax[v];
    for(int next : edge[v]){
        if(next == p)   continue;
        dfs(next, v, d+1);
    }
}

int lca(int u, int v){
    if(depth[u] > depth[v]) swap(u, v);
    for(int k = 0; k < 20; k++){
        if((depth[v]-depth[u])>>k & 1)  v = parent[k][v];
    }
    if(u == v)  return u;
    for(int k = 19; k >= 0; k--){
        if(parent[k][u] != parent[k][v]){
            u = parent[k][u];
            v = parent[k][v];
        }
    }
    return parent[0][u];
}

int main(){
    int n;
    cin >> n;
    for(int i = 1; i < n; i++){
        int a, b;   cin >> a >> b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    for(int i = 0; i < n; i++)  cin >> tax[i];
    
    dfs(0, -1, 0);
    for(int k = 0; k+1 < 20; k++){
        for(int j = 0; j < n; j++){
            if(parent[k][j] < 0)    parent[k+1][j] = -1;
            else                    parent[k+1][j] = parent[k][parent[k][j]];
        }
    }

    int m;
    cin >> m;
    ll ans = 0;
    while(m-- > 0){
        int a, b, c;
        cin >> a >> b >> c;
        int l = lca(a,b);
        ans += (atax[a]+atax[b]-2*(atax[l])+tax[l])*c;
    }
    
    cout << ans << endl;

    return 0;
}