// 後ろから見ていくと愚直な実装をせずに済むらしい
// testestestさんの解説を参考に
#include<iostream>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    int A[m];
    for(int i = 0; i < m; i++)  cin >> A[i];
    int res = A[m-1];
    for(int i = m-2; i >= 0; i--){
        if(res == 1){
            res = A[i];
        }else if(res > A[i]){
            // do nothing.
        }else{
            res--;
        }
    }
    cout << res << endl;
    return 0;
}