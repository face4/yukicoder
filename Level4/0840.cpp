// 自力AC
#include<iostream>
#include<vector>
using namespace std;

typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;
ll mod = 998244353;

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

int main(){
    int n, k;
    cin >> n >> k;
    int siz = k*k*k;
    mat A(siz, vec(siz, 0)), B(siz, vec(1,0));
    B[0][0] = 1;
    for(int i = 0; i < siz; i++){
        int x[3], cp = i;
        for(int j = 2; j >= 0; j--){
            x[j] = cp%k;
            cp /= k;
        }
        A[x[0]*k*k+x[1]*k+(x[2]+1)%k][i]++;
        A[x[0]*k*k+(x[1]+x[2])%k*k+x[2]][i]++;
        A[(x[0]+x[1])%k*k*k+x[1]*k+x[2]][i]++;
    }
    mat C = mul(pow(A, n), B);
    ll ans = 0;
    for(int i = 0; i < k*k; i++){
        (ans += C[i][0]) %= mod;
    }
    cout << ans << endl;
    return 0;
}