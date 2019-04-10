#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;

vector<pair<int,int>> v[200];
vector<int> u(200);
ll dp[200][2001];
int n, m;

// 葉から根に向かってボトムアップ
void dfs(int par, int cur){
    dp[cur][0] = u[cur];
    for(pair<int,int> p : v[cur]){
        if(p.first == par)  continue;
        dfs(cur, p.first);
        // 部分木をダブって使わないように後ろから更新
        for(int i = m; i >= 0; i--){
            for(int j = 0; j <= m; j++){
                int t = i+p.second*2+j;
                if(t <= m){
                    dp[cur][t] = max(dp[cur][t], dp[cur][i]+dp[p.first][j]);
                }
            }
        }
    }
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++)  cin >> u[i];
    int a, b, c;
    for(int i = 0; i < n-1 ; i++){
        cin >> a >> b >> c;
        v[a].push_back({b,c});
        v[b].push_back({a,c});
    }
    dfs(-1, 0);
    ll ans = 0;
    for(int i = 0; i <= m; i++) ans = max(ans, dp[0][i]);
    cout << ans << endl;
    return 0;
}