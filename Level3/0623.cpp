// 自力AC 普通にボトムアップにfを求めても良い
#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;

const ll mod = 998244353;

ll t[51], a[51], b[51];
vector<bool> vis(51);
vector<ll> memo(51);
int n;

ll f(ll x, int i){
    if(i == 0)  return memo[i] = 1;
    if(i == 1)  return memo[i] = x;
    if(vis[i])  return memo[i];
    vis[i] = true;
    if(t[i] == 1)   return memo[i] = (f(x, a[i]) + f(x, b[i]))%mod;
    if(t[i] == 2)   return memo[i] = a[i]*f(x,b[i])%mod;
    if(t[i] == 3)   return memo[i] = f(x, a[i])*f(x, b[i])%mod;
    return 0;   // unreachable
}

int main(){
    cin >> n;
    for(int i = 2; i <= n; i++){
        cin >> t[i] >> a[i] >> b[i];
    }
    int q;
    cin >> q;
    while(q-- > 0){
        fill(vis.begin(), vis.end(), false);
        fill(memo.begin(), memo.end(), 0);
        ll x;   cin >> x;
        cout << f(x, n) << endl;
    }
    return 0;
}