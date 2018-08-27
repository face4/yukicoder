#include<iostream>
#include<vector>
using namespace std;

typedef long long ll;
int mod = 1e9;

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
                dp[i][j] = (dp[i-1][j] + dp[i-1][j-1]) % mod;
            }
        }
    }

    // return aCb
    int getCombination(int a, int b){
        return dp[a][b];
    }
};

int main(){
    ll n;
    int m;
    cin >> n >> m;

    n /= 1000;

    Combination c(m);

    cout << c.getCombination(m, n%m) << endl;

    return 0;
}