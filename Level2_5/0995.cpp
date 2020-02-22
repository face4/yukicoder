#include<iostream>
#include<vector>
using namespace std;

typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;
ll mod = 1000000007;

mat mul(const mat &A, const mat &B){
    mat C(A.size(), vec(B[0].size()));
    for(int i = 0; i < A.size(); i++){
        for(int k = 0; k < B.size(); k++){
            for(int j = 0; j < B[0].size(); j++){
                C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % mod;
            }
        }
    }
    return C;
}

mat pow(mat A, ll n){
    mat B(A.size(), vec(A.size()));
    for(int i = 0; i < A.size(); i++){
        B[i][i] = 1ll;
    }
    while(n > 0){
        if(n & 1)   B = mul(B, A);
        A = mul(A, A);
        n >>= 1;
    }
    return B;
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
    int n, m;
    ll k, p, q;
    cin >> n >> m >> k >> p >> q;
    p *= modpow(q, mod-2, mod);
    p %= mod;
    mat A(2, vec(2, 0));
    A[0][0] = A[1][1] = (1-p+mod)%mod;
    A[0][1] = A[1][0] = p;
    A = pow(A, k);
    ll ans = 0;
    for(int i = 0; i < n; i++){
        ll b;
        cin >> b;
        ans += A[0][!(i<m)]*b%mod;
        ans %= mod;
    }
    cout << ans << endl;
    return 0;
}