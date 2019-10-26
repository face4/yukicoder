#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;

vector<int> v[100000], w[100000];
vector<ll> dist(100000, 0);
int root;

int parent[20][100000];
int depth[100000];

void dfs(int x, int p, int d){
    parent[0][x] = p;
    depth[x] = d;
    for(int i = 0; i < v[x].size(); i++){
        if(v[x][i] != p)    dist[v[x][i]] = dist[x]+w[x][i], dfs(v[x][i], x, d+1);
    }
}

void init(int n){
    dfs(root, -1, 0);
    for(int k = 0; k+1 < 20; k++){
        for(int x = 0; x < n; x++){
            if(parent[k][x] < 0)    parent[k+1][x] = -1;
            else                    parent[k+1][x] = parent[k][parent[k][x]];
        }
    }
}

int lca(int a, int b){
    if(depth[a] > depth[b]) swap(a, b);
    for(int k = 0; k < 20; k++){
        if((depth[b]-depth[a])>>k&1){
            b = parent[k][b];
        }
    }
    if(a == b)  return a;
    for(int k = 19; k >= 0; k--){
        if(parent[k][b] != parent[k][a]){
            b = parent[k][b];
            a = parent[k][a];
        }
    }
    return parent[0][a];
}

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n-1; i++){
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back(b);  w[a].push_back(c);
        v[b].push_back(a);  w[b].push_back(c);
    }
    init(n);
    int q;
    cin >> q;
    while(q-- > 0){
        int x[3];
        for(int i = 0; i < 3; i++)  cin >> x[i];
        ll ans = 0;
        for(int i = 0; i < 3; i++){
            int p = lca(x[i], x[(i+1)%3]);
            ans += dist[x[i]]+dist[x[(i+1)%3]]-2*dist[p];
        }
        cout << ans/2 << endl;
    }
    return 0;
}