#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;

const int mod = 1000000007;

ll modpow(ll a, ll b, ll p = 1e9+7){
    if(b == 0)  return 1;

    if(b % 2 == 0){
        ll d = modpow(a, b/2, p);
        return (d*d) % p;
    }else{
        return (a%p * modpow(a, b-1, p)) % p;
    }
}

ll fact[76], invf[76];

void init(){
    fact[0] = invf[0] = 1;
    for(int i = 1; i <= 75; i++){
        fact[i] = fact[i-1]*i%mod;
        invf[i] = invf[i-1]*modpow(i, mod-2)%mod;
    }
}

int gx, gy, k, x[5], y[5], z[5], tmp[5];

ll ans = 0;

void dfs(int sx, int sy, int id){
    if(id == k){
        if(sx != gx || sy != gy)    return;
        int sum = 0;
        for(int i = 0; i < k; i++)  sum += tmp[i];
        ll add = fact[sum];
        for(int i = 0; i < k; i++)  add = add * invf[tmp[i]] % mod;
        ans = (ans + add) % mod;
        return;
    }
    for(int i = 0; i <= z[id]; i++){
        tmp[id] = i;
        dfs(sx+i*x[id], sy+i*y[id], id+1);
    }
}

int main(){
    init();
    cin >> gx >> gy >> k;
    for(int i = 0; i < k; i++){
        cin >> x[i] >> y[i] >> z[i];
    }
    dfs(0, 0, 0);
    cout << ans << endl;
    return 0;
}