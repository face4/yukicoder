#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
const int mod = 1000000007;

void minusone(string &s){
    reverse(s.begin(), s.end());
    int carry = 1;
    for(int i = 0; carry > 0 && i < s.length(); i++){
        carry = s[i] == '0';
        s[i] = (s[i] == '0' ? '9' : s[i]-1);
    }
    reverse(s.begin(), s.end());
    if(s.length() > 1 && s[0] == '0') s = s.substr(1);
}

// index - less - has three - modulo three - modulo eight
int dp[10001][2][2][3][8];

int f(string s){
    memset(dp, 0, sizeof(dp));
    int n = s.length();
    dp[0][0][0][0][0] = 1;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 2; j++){
            for(int k = 0; k < 2; k++){
                for(int l = 0; l < 3; l++){
                    for(int m = 0; m < 8; m++){
                        for(int num = 0; num <= 9; num++){
                            if(j == 0 && num > s[i]-'0')    continue;
                            int ni = i+1;
                            int nj = j | (num < s[i]-'0');
                            int nk = k | (num == 3);
                            int nl = (10*l+num)%3;
                            int nm = (10*m+num)%8;
                            dp[ni][nj][nk][nl][nm] += dp[i][j][k][l][m];
                            dp[ni][nj][nk][nl][nm] %= mod;
                        }
                    }
                }
            }
        }
    }
    int ret = 0;
    for(int j = 0; j < 2; j++){
        for(int k = 0; k < 2; k++){
            for(int l = 0; l < 3; l++){
                if(k == 0 && l != 0)    continue;
                for(int m = 1; m < 8; m++){
                    ret += dp[n][j][k][l][m];
                    ret %= mod;
                }
            }
        }
    }
    return ret;
}

int main(){
    string a, b;
    cin >> a >> b;
    minusone(a);
    cout << (f(b)-f(a)+mod)%mod << endl;
    return 0;
}