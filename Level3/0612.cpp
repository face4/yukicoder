// 自力AC
#include<iostream>
#include<vector>
using namespace std;
const int mod = 1000000007;
#define inRange(x,a,b) (a <= x && x < b)

int main(){
    int t, a[3], d, e;
    cin >> t >> a[0] >> a[1] >> a[2] >> d >> e;
    vector<int> dp(20001, 0);
    dp[10000] = 1;
    while(t-- > 0){
        vector<int> ndp(20001, 0);
        for(int i = 0; i < 3; i++){
            for(int j : {-1, 1}){
                for(int k = 0; k <= 20000; k++){
                    if(inRange(k+j*a[i], 0, 20001)){
                        (ndp[k+j*a[i]] += dp[k]) %= mod;
                    }
                }
            }
        }
        dp = ndp;
    }
    int ans = 0;
    for(int i = d+10000; i <= e+10000; i++) (ans += dp[i]) %= mod;
    cout << ans << endl;
    return 0;
}