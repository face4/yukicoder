#include<iostream>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); i++)

typedef long long ll;

int main(){
    int p;
    cin >> p;

    string s = "";
    rep(i, p)    s += "9";
    
    int n = s.length();

    ll dp[20][2][2][3] = {}; // pos, less, has3, mod3
    dp[0][0][0][0] = 1;

    rep(i,n) rep(j,2) rep(k,2) rep(l,3) {
        int lim = j ? 9 : s[i]-'0';
        rep(d, lim+1){
            dp[i+1][j || d < lim][k || d==3][(l+d)%3] += dp[i][j][k][l];
        }
    }

    ll ans = 0;
    rep(j,2) rep(k,2) rep(l,3){
        if(k || l == 0){
            ans += dp[n][j][k][l];
        }
    }

    // ansには0が3の倍数としてカウントされてしまっているので、その分を引く
    cout << ans-1 << endl;

    return 0;
}