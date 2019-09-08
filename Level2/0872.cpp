#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<pair<int,int>> v[200000];
vector<int> child(200000, 0), par(200000, 0), dep(200000, 0);

int dfs(int pos, int bef){
    dep[pos] = bef==-1 ? 0 : dep[bef]+1;
    par[pos] = bef;
    child[pos] = 1;
    for(auto p : v[pos]){
        if(p.first != par[pos]){
            child[pos] += dfs(p.first, pos);
        }
    }
    return child[pos];
}

typedef long long ll;

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n-1; i++){
        int a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        v[a].push_back({b, c});
        v[b].push_back({a, c});
    }
    dfs(0, -1);
    ll ans = 0;
    for(int i = 0; i < n; i++){
        for(auto p : v[i]){
            ll num = (dep[i] > dep[p.first] ? child[i] : child[p.first]);
            ans += (ll)p.second * num * (n-num);
        }
    }
    cout << ans << endl;
    return 0;
}