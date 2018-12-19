#include<iostream>
#include<vector>
#include<cstring>
#include<stack>
using namespace std;

int dp[100000][2] = {};
bool memo[100000][2] = {};
vector<int> path[100000];

int dfs(int cur, int par, int flag){
    if(memo[cur][flag]) return dp[cur][flag];

    memo[cur][flag] = true;

    int ret = flag;

    if(flag){
        for(int next : path[cur]){
            if(next == par) continue;
            ret += dfs(next, cur, 0);
        }
    }else{
        for(int next : path[cur]){
            if(next == par)  continue;
            ret += max(dfs(next, cur, 0), dfs(next, cur, 1));
        }
    }

    dp[cur][flag] = ret;

    return ret;
}

int main(){
    int n;
    cin >> n;

    int u, v;
    for(int i = 0; i < n-1; i++){
        cin >> u >> v;
        u--, v--;
        path[u].push_back(v);
        path[v].push_back(u);
    }

    cout << max(dfs(0, -1, 0) , dfs(0, -1, 1)) << endl;

    return 0;
}