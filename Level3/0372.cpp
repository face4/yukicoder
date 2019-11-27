// 自力AC
#include<iostream>
#include<vector>
using namespace std;

const int mod = 1000000007;

int main(){
    string s;
    int m;
    cin >> s >> m;
    int n = s.length();
    vector<int> dp(m+1, 0);
    dp[0] = 1;
    int zero = 0;
    for(int i = 0; i < n; i++){
        zero += s[i]=='0';
        vector<int> ndp = dp;
        for(int j = 0; j <= m; j++){
            if(j == 0 && s[i] == '0')   continue;
            int x = ((j==m ? 0 : j*10) + s[i]-'0')%m;
            (ndp[x == 0 ? m : x] += dp[j]) %= mod;
        }
        dp = ndp;
    }
    cout << zero+dp.back() << endl;
    return 0;
}