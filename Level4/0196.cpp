// なんか気持ち悪い
#include<iostream>
#include<vector>
using namespace std;

typedef long long ll;
const int mod = 1e9+7;
vector<int> v[2001];
int dp[2001][2001] = {}, child[2001] = {};

void dfs(int x, int p){
    child[x] = 1;
    for(int next : v[x]){
        if(next == p)   continue;
        dfs(next, x);
        child[x] += child[next];
    }
}

void dfs2(int x, int p){
    dp[x][0] = 1;
    for(int next : v[x]){
        if(next == p)   continue;
        dfs2(next, x);
        for(int i = child[x]-child[next]; i >= 0; i--){
            for(int j = child[next]; j > 0; j--){
                (dp[x][i+j] += (ll)dp[x][i]*dp[next][j]%mod) %= mod;
            }
        }
    }
    dp[x][child[x]] = 1;
}

int main(){
    int n, k;
    cin >> n >> k;
    for(int i = 0; i < n-1; i++){
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    dfs(0, -1);
    dfs2(0, -1);
    cout << dp[0][k] << endl;
    return 0;
}
