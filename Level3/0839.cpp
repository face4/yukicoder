#include<iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    int ans[n][n];
    int val = 1;
    for(int i = 0; i < n/2; i++){
        for(int j = 0; j < n/2; j++){
            ans[i][j] = val++;
            ans[i+n/2][j+n/2] = val++;
        }
    }
    for(int i = 0; i < n/2; i++){
        for(int j = n-1; j >= n/2; j--){
            ans[i][j] = val++;
            ans[i+n/2][j-n/2] = val++;
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << ans[i][j] << " \n"[j==n-1];
        }
    }
    return 0;
}