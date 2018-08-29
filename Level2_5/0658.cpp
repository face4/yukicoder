#include<iostream>
#include<vector>
using namespace std;

typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;
ll mod = 17;

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
    int q;
    cin >> q;
    while(q-- > 0){
        mat A(4, vec(4));
        A[0][0] = 1; A[0][1] = 1; A[0][2] = 1; A[0][3] = 1;
        A[1][0] = 1; A[2][1] = 1; A[3][2] = 1;

        ll n;
        cin >> n;
        
        A = pow(A, n);

        cout << A[3][3] % mod << endl;
    }
    return 0;
}