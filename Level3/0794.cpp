#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

typedef long long ll;
const ll mod = 1000000007;

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
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for(int i = 0; i < n; i++)  cin >> v[i];
    sort(v.begin(), v.end());
    ll ans = 1, stock = 0, pos = -1;
    for(int i = n-1; i >= n/2; i--){
        int next = upper_bound(v.begin(), v.end(), k-v[i])-v.begin()-1;
        stock += next-pos;
        pos = next;
        if(stock == 0){
            cout << 0 << endl;
            return 0;
        }else if(pos >= i){
            int res = (i-n/2+1)*2;
            ll tmp = 1;
            while(res > 0){
                (tmp *= (ll)res*(res-1)%mod*modpow(2,mod-2)%mod*modpow(res/2,mod-2)%mod) %= mod;
                res -= 2;
            }
            (ans *= tmp) %= mod;
            break;
        }
        (ans *= stock--) %= mod;
    }
    cout << ans << endl;
    return 0;
}