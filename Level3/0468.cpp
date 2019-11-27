#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> indeg(n, 0), dp(n, 0);
    vector<pair<int,int>> v[n], rev[n];
    for(int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back({b, c});
        rev[b].push_back({a,c});
        indeg[b]++;
    }
    vector<bool> busy(n, 0);
    busy[0] = busy[n-1] = true;
    queue<int> q;
    q.push(0);
    while(!q.empty()){
        int x = q.front();  q.pop();
        for(auto p : v[x]){
            dp[p.first] = max(dp[x]+p.second, dp[p.first]);
            indeg[p.first]--;
            if(indeg[p.first] == 0) q.push(p.first);
        }
    }
    q.push(n-1);
    while(!q.empty()){
        int x = q.front();  q.pop();
        for(auto p : rev[x]){
            if(dp[x]-p.second == dp[p.first] && !busy[p.first]){
                busy[p.first] = true;
                q.push(p.first);
            }
        }
    }
    int k = n;
    for(int i = 0; i < n; i++)  k -= busy[i];
    cout << dp.back() << " " << k << "/" << n << endl;
    return 0;
}