// フェルマーの小定理 a^(p-1) = 1 mod p (aとpは互いに素)
#include<iostream>
#include<vector>
using namespace std;

typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;
ll mod = 1000000007;

mat mul(mat &A, mat &B){
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

ll fib(ll n){
    if(n == 1)  return 2;
    if(n == 2)  return 3;
    n -= 2;
    mat A(2, vec(2, 1));
    A[1][1] = 0;
    A = pow(A, n);
    return (A[0][0]*3+A[0][1]*2)%mod;
}

ll modpow(ll a, ll b, ll p = 1e9+7){
    if(a == 0)  return 0;
    if(b == 0)  return 1;

    if(b % 2 == 0){
        ll d = modpow(a, b/2, p);
        return (d*d) % p;
    }else{
        return (a%p * modpow(a, b-1, p)) % p;
    }
}

int main(){
    int n;
    cin >> n;
    ll ans = 1;
    for(int i = 0; i < n; i++){
        ll c;
        string d;
        cin >> c >> d;
        ll tmp = fib(c);
        ll power = 0;
        for(char x : d) power = (power*10+x-'0')%(mod-1);
        ans *= modpow(tmp, power);
        ans %= mod;
    }
    cout << ans << endl;
    return 0;
}