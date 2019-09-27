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

// 使用例. yukicoder No.718
int main(){
    ll a, b, n;
    cin >> a >> b >> n;

    if(n == 0){
        cout << 0 << endl;
        return 0;
    }

    mat A(2, vec(2));
    A[0][0] = a; A[0][1] = b;
    A[1][0] = 1; A[1][1] = 0;
    A = pow(A, n-1);

    cout << A[0][0] << endl;
    return 0;
}