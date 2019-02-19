// 解説を読んだ
#include<iostream>
#include<vector>
using namespace std;

typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;

mat mul(mat A, mat B){
    mat C(A.size(), vec(B[0].size()));
    for(int i = 0; i < A.size(); i++){
        for(int k = 0; k < B.size(); k++){
            for(int j = 0; j < B[0].size(); j++){
                C[i][j] = (C[i][j] + A[i][k] * B[k][j]);
            }
        }
    }
    return C;
}

mat getT(int i, int d){
    mat ret(3, vec(3, 0));
    if(i == 1)  ret[0][0] = ret[1][1] = 1, ret[0][2] = d;
    if(i == 2)  ret[0][0] = ret[1][1] = 1, ret[1][2] = d;
    if(i == 3)  ret[0][1] = 1, ret[1][0] = -1;
    ret[2][2] = 1;
    return ret;
}

int main(){
    int n, x, y;
    cin >> n >> x >> y;
    int op[n], d[n];
    for(int i = 0; i < n; i++){
        cin >> op[i];
        if(op[i] != 3)  cin >> d[i];
    }
    mat v(3, vec(1));
    v[0][0] = x, v[1][0] = y, v[2][0] = 1;
    
    vector<pair<int,int>> ans;
    mat accum(3, vec(3, 0));
    for(int i = 0; i < 3; i++)  accum[i][i] = 1;

    for(int i = 0; i < n; i++){
        accum = mul(accum, getT(op[n-1-i], d[n-1-i]));
        mat tmp = mul(accum, v);
        ans.push_back({tmp[0][0], tmp[1][0]});
    }

    for(int i = n-1; i >= 0; i--){
        cout << ans[i].first << " " << ans[i].second << endl;
    }

    return 0;
}