#include<iostream>
#include<vector>
using namespace std;

vector<int> v[200000], child, way[200000];

void dfs(int p, int x){
    child[x] = 1;
    for(int c : v[x]){
        if(c == p)  continue;
        dfs(x, c);
        way[x].push_back(c);
        child[x] += child[c];
    }
}

typedef long long ll;

int main(){
    int n;
    cin >> n;
    child.resize(n, 0);
    for(int i = 0; i < n-1; i++){
        int a, b;
        cin >> a >> b;
        a--, b--;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    dfs(-1, 0);
    for(int i = 0; i < n; i++){
        ll ans = 2*child[i]-1;
        for(int c : way[i]){
            ans += (ll)child[c]*(child[i]-1-child[c]);
        }
        cout << ans << endl;
    }
    return 0;
}