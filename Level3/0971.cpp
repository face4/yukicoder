#include<iostream>
#include<vector>
using namespace std;

int main(){
    int h, w;
    cin >> h >> w;
    vector<vector<int>> dp(h, vector<int>(w, 1<<30));
    char mat[h][w];
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            cin >> mat[i][j];
        }
    }
    dp[0][0] = 0;
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            if(i+1 < h){
                dp[i+1][j] = min(dp[i+1][j], (mat[i+1][j]=='k' ? i+j+1 : 0) + dp[i][j] + 1);
            }
            if(j+1 < w){
                dp[i][j+1] = min(dp[i][j+1], (mat[i][j+1]=='k' ? i+j+1 : 0) + dp[i][j] + 1);
            }
        }
    }
    cout << dp[h-1][w-1] << endl;
    return 0;
}