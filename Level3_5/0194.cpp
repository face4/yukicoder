#include<iostream>
#include<queue>
#include<vector>
using namespace std;
const int mod = 1e9+7;
typedef long long ll;

typedef vector<ll> vec;
typedef vector<vec> mat;

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
    int n;
    ll k;
    cin >> n >> k;
    // skの求め方がわからなかったのでeditorialを見た　賢い
    if(n <= 30){
        mat A(n+1, vec(n+1, 0));
        for(int j = 0; j <= n; j++) A[0][j] = 1;
        for(int j = 1; j <= n; j++) A[1][j] = 1;
        for(int i = 2; i <= n; i++){
            A[i][i-1] = 1;
        }
        mat B(n+1, vec(1));
        ll tmp = 0;
        for(int i = 1; i <= n; i++) cin >> B[n-i+1][0], tmp += B[n-i+1][0];
        B[0][0] = tmp;
        mat C = mul(pow(A, k-n), B);
        cout << C[1][0] << " " << C[0][0] << endl;
    }else{
        deque<int> q;
        ll sum = 0;
        for(int i = 0; i < n; i++){
            int x;  cin >> x;
            q.push_back(x);
            sum += x;
        }
        ll sk = sum;
        for(int i = 0; i < k-n; i++){
            (sk += sum) %= mod;
            q.push_back(sum);
            sum = (sum*2)%mod;
            sum -= q.front();   q.pop_front();
            sum = (sum+mod)%mod;
        }
        cout << q.back() << " " << sk << endl;
    }
    return 0;
}
