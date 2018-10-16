#include<iostream>
#include<vector>
using namespace std;

typedef long long ll;
const ll mod = 1e9 + 7;

ll modpow(ll a, ll b, ll p = 1e9+7){
    if(b == 0)  return 1;

    if(b % 2 == 0){
        ll d = modpow(a, b/2, p);
        return (d*d) % p;
    }else{
        return (a%p * modpow(a, b-1, p)) % p;
    }
}

#define N 2000005
ll po[N], inv[N];

void init(){
    po[0] = 1;
    for(int i = 1; i < N; i++)  po[i] = (po[i-1] * i) % mod;
    inv[N-1] = modpow(po[N-1], mod-2, mod);
    for(int i = N-2; i >= 0; i--)   inv[i] = (inv[i+1] * (i+1)) % mod;
}

ll nCk(ll n, ll k){
    if(n < k)   return 0;
    return (((po[n]*inv[n-k])%mod)*inv[k])%mod;
}

ll nPk(ll n, ll k){
    if(n < k)   return 0;
    return (po[n]*inv[n-k])%mod;
}

ll nHk(ll n, ll k){
    if(n == 0 && k == 0)    return 1;
    return nCk(n+k-1, k);
}

int main(){
    init();

    int t;
    scanf("%d\n", &t);

    char c;
    int n, k;
    for(int i = 0; i < t; i++){
        scanf("%c(%d,%d)\n", &c, &n, &k);
        
        if(c == 'C')            cout << nCk(n,k) << endl;
        else if(c == 'P')       cout << nPk(n,k) << endl;
        else if(c == 'H')       cout << nHk(n,k) << endl;
    }

    return 0;
}