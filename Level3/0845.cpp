#include<iostream>
#include<vector>
using namespace std;

const int INF = 1<<30;

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> v(n, vector<int>(n, 0));
    while(m-- > 0){
        int a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        int val = max(v[a][b], c);
        v[a][b] = v[b][a] = val;
    }

    int ans = 0;
    vector<vector<int>> dp(n, vector<int>(1<<n, -1));
    for(int i = 0; i < n; i++)  dp[i][1<<i] = 0;
    for(int s = 0; s < 1<<n; s++){
        for(int i = 0; i < n; i++){
            if(dp[i][s] == -1)  continue;
            for(int j = 0; j < n; j++){
                if(v[i][j] == 0)    continue;
                if((s>>j) & 1)  continue;
                dp[j][s|(1<<j)] = max(dp[j][s|(1<<j)], dp[i][s] + v[i][j]);
                ans = max(ans, dp[j][s|(1<<j)]);
            }
        }
    }
    cout << ans << endl;
    
    return 0;
}