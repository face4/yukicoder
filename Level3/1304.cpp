#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
const ll mod = 998244353;

int dp[2][1<<10][1<<10] = {};

int main(){
    int n, k, x, y;
    cin >> n >> k >> x >> y;
    vector<int> v;
    for(int i = 0; i < k; i++){
        int a;
        cin >> a;
        v.push_back(a);
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    ll sum[1<<10] = {};
    sum[0] = 1;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 1<<10; j++){
            for(int t : v){
                dp[1][t][j] = (sum[t^j]-dp[0][t][t^j]+mod)%mod;
            }
        }
        swap(dp[0], dp[1]);
        memset(dp[1], 0, sizeof(dp[1]));
        for(int j = 0; j < 1<<10; j++){
            sum[j] = 0;
            for(int l = 0; l < 1<<10; l++){
                sum[j] += dp[0][l][j];
            }
            sum[j] %= mod;
        }
    }
    ll ans = 0;
    for(int i = x; i <= min(1023, y); i++){
        (ans += sum[i]) %= mod;
    }
    cout << ans << endl;
    return 0;
}