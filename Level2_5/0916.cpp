#include<iostream>
using namespace std;

typedef long long ll;
const int mod = 1000000007;

int f(int x){
    int ret = 0;
    while(x)    ret++, x>>=1;
    return ret;
}

ll modpow(ll a, ll b, ll p = 1e9+7){
    if(b == 0)  return 1;

    if(b % 2 == 0){
        ll d = modpow(a, b/2, p);
        return (d*d) % p;
    }else{
        return (a%p * modpow(a, b-1, p)) % p;
    }
}

int main(){
    int d, l, r, k;
    cin >> d >> l >> r >> k;
    int depl = f(l), depr = f(r);
    if(abs(depl-depr) > k || abs(depl-depr)%2 != k%2 || depl-1+depr-1 < k){
        cout << 0 << endl;
        return 0;
    }
    int deplca = min(depl,depr)-(k-abs(depl-depr))/2;
    ll ans = (1ll<<(depr-deplca)) * (1<<(depl-deplca)) %mod * modpow((depl==deplca||depr==deplca)?1:2,mod-2) % mod;
    ans *= 1<<(deplca-1);
    ans %= mod;
    for(int i = 1; i <= d; i++){
        int tmp = 1<<(i-1);
        tmp -= (i==depl) + (i==depr);
        while(tmp)  ans = ans*tmp--%mod;
    }
    cout << ans << endl;
    return 0;
}