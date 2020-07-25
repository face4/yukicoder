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

int main(){
    ll n, a[3];
    cin >> n;
    for(int i = 0; i < 3; i++)  cin >> a[i];
    mat x(3, vec(1));
    for(int i = 0; i < 3; i++)  x[i][0] = a[i];
    mat A(3, vec(3, 0));
    for(int i = 0; i < 3; i++){
        A[i][i] = 1;
        A[i][(i+1)%3] = -1+mod;
    }
    A = pow(A, --n);
    x = mul(A, x);
    for(int i = 0; i < 3; i++)  cout << x[i][0] << " \n"[i==2];
    return 0;
}
