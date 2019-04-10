#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n;  cin >> n;
    int f[n][n];
    for(int i = 0; i < n; i++)  for(int j = 0; j < n; j++)  cin >> f[i][j];
    vector<int> dp(1<<n, -1);
    dp[0] = 0;
    for(int i = 0; i < 1<<n; i++){
        if(dp[i] < 0)   continue;
        int j;
        for(j = 0; j < n; j++)  if(((i>>j)&1)==0)   break;
        for(int k = j+1; k < n; k++){
            if((i>>k)&1)   continue;
            dp[i|(1<<j)|(1<<k)] = max(dp[i|(1<<j)|(1<<k)], dp[i]+f[j][k]);
        }
    }
    cout << dp[(1<<n)-1] << endl;
    return 0;
}