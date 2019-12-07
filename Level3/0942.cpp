#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    if(n == k){
        if(k == 1){
            cout << "Yes" << endl;
            for(int i = 1; i <= n; i++) cout << i << " \n"[i==n];
        }else{
            cout << "No" << endl;
        }
        return 0;
    }
    int m = n/k;
    if(n%2 == 0 && m%2 == 1){
        cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl;
    vector<vector<int>> ans(k, vector<int>(n/k));
    if(m%2 == 0){
        for(int i = 0; i < n/k; i++){
            int base = i*k+1;
            for(int j = 0; j < k; j++){
                ans[j][i] = i%2==0 ? base+j : base+k-1-j;
            }
        }
    }else{
        // これは思い付けない
        for(int i = 0; i < k; i++)  ans[i][0] = 1   + i;
        for(int i = 0; i < k; i++)  ans[i][1] = k+1 + (k/2+i)%k;
        for(int i = 0; i < k; i++)  ans[i][2] = 3 * (3*k+1) / 2 - ans[i][0] - ans[i][1];
        for(int j = 3; j < n/k; j++){
            int base = j*k+1;
            for(int i = 0; i < k; i++){
                ans[i][j] = base + (j%2==0 ? i : k-1-i);
            }
        } 
    }
    for(int i = 0; i < k; i++){
        for(int j = 0; j < n/k; j++){
            cout << ans[i][j] << " \n"[j==n/k-1];
        }
    }
    return 0;
}