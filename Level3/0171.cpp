#include<iostream>
#include<vector>
using namespace std;

const int mod = 573;

struct Combination{
    int n;
    vector<vector<int>> dp;

    Combination(int i){
        n = i;
        dp = vector<vector<int>>(n+1, vector<int>(n+1, 0));
        constructTriangle();
    }

    void constructTriangle(){
        dp[0][0] = 1;
        for(int i = 1; i <= n; i++){
            dp[i][0] = dp[i-1][0];
            for(int j = 1; j <= i; j++){
                dp[i][j] = (dp[i-1][j] + dp[i-1][j-1])%mod;
            }
        }
    }

    // return aCb
    int getCombination(int a, int b){
        return dp[a][b];
    }
};

int main(){
    string s;
    cin >> s;

    int n = s.length();
    Combination c(n);
    int appear[26] = {};

    for(int i = 0; i < n; i++)  appear[s[i]-'A']++;

    long long ans = 1;
    for(int i = 0; i < 26; i++){
        if(appear[i]){
            ans *= c.getCombination(n, appear[i]);
            ans %= mod;
            n -= appear[i];
        }
    }

    cout << (ans+mod-1) % mod << endl;

    return 0;
}