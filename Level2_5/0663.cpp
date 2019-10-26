#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

int automaton(int i, int j, int k){
    if(j+k == 0 || i+j+k == 3)  return 0;
    return 1;
}

const int mod = 1000000007;
int dp[2000][2][2];
typedef long long ll;

int main(){
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++)  cin >> v[i];
    ll ans = 0;
    for(int s = 0; s < 1<<3; s++){
        memset(dp, 0, sizeof(dp));
        if(automaton(s&1, (s>>1)&1, (s>>2)&1) != v[0])    continue;
        dp[1][(s>>1)&1][(s>>2)&1]++;
        for(int i = 1; i+1 < n; i++){
            for(int j = 0; j < 2; j++){
                for(int k = 0; k < 2; k++){
                    for(int l = 0; l < 2; l++){
                       if(automaton(j, k, l) == v[i]){
                           dp[i+1][k][l] += dp[i][j][k];
                           dp[i+1][k][l] %= mod;
                       } 
                    }
                }
            }
        }
        for(int j = 0; j < 2; j++){
            if(automaton(j, s&1, (s>>1)&1) == v[n-1]){
                ans += dp[n-1][j][s&1];
                ans %= mod;
            }
        }
    }
    cout << ans << endl;
    return 0;
}