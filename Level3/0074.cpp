// O(N^4) 掃き出し法
#include<iostream>
#include<vector>
#include<numeric>
using namespace std;

int main(){
    int n;
    cin >> n;
    int d[n], w[n];
    for(int i = 0; i < n; i++)  cin >> d[i];
    for(int i = 0; i < n; i++)  cin >> w[i], w[i] = 1-w[i];
    vector<vector<int>> v(n, vector<int>(n,0));
    for(int i = 0; i < n; i++){
        v[i][(i+d[i])%n] = v[i][(i-d[i]+n*2000)%n] = 1;
    }
    int rank = 0;
    for(int j = 0; j < n; j++){
        for(int i = rank; i < n; i++){
            if(v[i][j] == 1){
                swap(v[i], v[rank]);
                for(int ii = 0; ii < n; ii++){
                    if(ii == rank)  continue;
                    if(v[ii][j] == 0)   continue;
                    for(int jj = 0; jj < n; jj++)    v[ii][jj] ^= v[rank][jj];
                }
                rank++;
                break;
            }
        }
    }
    for(int j = 0; j < n; j++){
        if(w[j] == 0)   continue;
        for(int i = 0; i < n; i++){
            if(v[i][j] == 1){
                for(int k = 0; k < n; k++)  w[k] ^= v[i][k];
                break;
            }
        }
    }
    cout << (accumulate(w, w+n, 0) == 0 ? "Yes" : "No") << endl;
    return 0;
}