#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;

int main(){
    int h, w, k, p;
    cin >> h >> w >> k >> p;
    h++, w++;
    int hh[k], ww[k];
    string s[k];
    vector<vector<bool>> ok(h, vector<bool>(w, 1));
    for(int i = 0; i < k; i++){
        cin >> hh[i] >> ww[i] >> s[i];
        ok[hh[i]][ww[i]] = false;
    }
    ll ans = 0;
    vector<string> ret;
    for(int i = 0; i < 1<<k; i++){
        vector<int> pass;
        for(int j = 0; j < k; j++)  if((i>>j)&1)    pass.push_back(j);
        if(pass.size() != p)    continue;
        vector<vector<ll>> dp(h, vector<ll>(w, 0));
        for(int j = 0; j < k; j++)  if((i>>j)&1)    ok[hh[j]][ww[j]] = true;
        dp[0][0] = 1;
        {
            for(int i = 0; i < h; i++){
                for(int j = 0; j < w; j++){
                    if(j+1 < w && ok[i][j+1])   dp[i][j+1] += dp[i][j];
                    if(i+1 < h && ok[i+1][j])   dp[i+1][j] += dp[i][j];
                }
            }
        }
        if(dp[h-1][w-1] > ans){
            ans = dp[h-1][w-1];
            vector<string> tmp;
            for(int j = 0; j < k; j++)  if((i>>j)&1)    tmp.push_back(s[j]);
            ret = tmp;
        }
        for(int j = 0; j < k; j++)  if((i>>j)&1)    ok[hh[j]][ww[j]] = false;
    }
    cout << ans%1000000007 << endl;
    for(string f : ret) cout << f << endl;
    return 0;
}