#include<iostream>
using namespace std;

typedef long long ll;
ll mod = 1e9 + 7;

int main(){
    int n;
    cin >> n;

    ll dp[10] = {};
    
    for(int i = 0; i < 10; i++) dp[i] = 1;

    for(int i = 1; i < n; i++){
        ll next[10] = {};
        for(int j = 0; j < 10; j++){
            for(int k = 0; k <= j; k++){
                next[j] = (next[j] + dp[k]) % mod;
            }
        }
        for(int i = 0; i < 10; i++) dp[i] = next[i];
    }

    ll ans = 1;
    for(int i = 1; i < 10; i++) ans = (ans + dp[i]) % mod;

    cout << ans << endl;

    return 0;
}