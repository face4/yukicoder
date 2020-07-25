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
    int k, m;
    ll n;
    cin >> k >> m >> n;
    mat x(k*k, vec(1));
    for(int i = 0; i < k*k; i++)    x[i][0] = i<k;
    vector<int> avail[70];
    for(int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        avail[10*a+b].push_back(c);
    }
    vector<int> kk(k*k);
    for(int i = 0; i < k*k; i++)    kk[i] = (i/k+1)*10+i%k+1;
    mat A(k*k, vec(k*k, 0));
    for(int i = 0; i < k*k; i++){
        for(int x : avail[kk[i]]){
            int next = kk[i]%10*10+x;
            for(int l = 0; l < k*k; l++){   // 面倒なのでサボり
                if(next == kk[l])   A[l][i]++;
            }
        }
    }
    A = pow(A, n-2);
    x = mul(A, x);
    int ans = 0;
    for(int i = 0; i < k*k; i += k) (ans += x[i][0]) %= mod;
    cout << ans << endl;
    return 0;
}