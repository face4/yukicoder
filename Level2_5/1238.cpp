#include<iostream>
#include<map>
using namespace std;

typedef pair<int,int> pii;

int main(){
    int n, k;
    cin >> n >> k;
    int a[n];
    for(int i = 0; i < n; i++)  cin >> a[i], a[i] -= k;
    const int mod = 1000000007;
    map<int,int> dp;
    dp[0] = 1;
    for(int i = 0; i < n; i++){
        map<int,int> ndp = dp;
        for(pii p : dp){
            (ndp[p.first+a[i]] += p.second) %= mod;
        }
        dp = ndp;
    }
    int ans = 0;
    for(pii p : dp){
        if(p.first >= 0)    (ans += p.second) %= mod;
    }
    cout << (ans+mod-1)%mod << endl;
    return 0;
}