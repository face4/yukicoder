#include<iostream>
using namespace std;
typedef long long ll;

const ll mod = 1e9+9;

int dp1[202][2][2000] = {};
int dp2[202][2][2000] = {};

void f(const string s, int dp[202][2][2000]){
    int n = s.length();
    dp[0][0][0] = 1;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 2; j++){
            for(int k = 0; k < 2000; k++){
                if(dp[i][j][k] == 0)    continue;
                for(int num = 0; num < 10; num++){
                    if(j == 0 && num > s[i]-'0')    break;
                    int ni = i+1;
                    int nj = j | (num < s[i]-'0');
                    int nk = k+num;
                    dp[ni][nj][nk] += dp[i][j][k];
                    dp[ni][nj][nk] %= mod;
                }
            }
        }
    }
}

int main(){
    string m, d;
    cin >> m >> d;
    f(m, dp1);    
    f(d, dp2);
    ll ans = 0;
    int mlen = m.length(), dlen = d.length();
    for(int i = 1; i < 2000; i++){
        ll a = (dp1[mlen][0][i]+dp1[mlen][1][i])%mod;
        ll b = (dp2[dlen][0][i]+dp2[dlen][1][i])%mod;
        ans += a*b%mod;
        ans %= mod;
    }
    cout << ans << endl;
    return 0;
}
