#include<iostream>
#include<cstring>
using namespace std;

int main(){
    int n;
    cin >> n;

    int d[n];
    for(int i = 0; i < n; i++)  cin >> d[i];

    int dp[1<<n];
    memset(dp, 0, sizeof(dp));

    dp[0] = 100;

    for(int i = 1; i < 1<<n; i++){
        int beat = 0;
        for(int j = 0; j < n; j++)  if((1<<j)&i && d[j] < 0)    beat++;

        for(int j = 0; j < n; j++){
            if((1<<j) & i == 0) continue;
            if(dp[(1<<j)^i] == 0)   continue;
            dp[i] = max(dp[i], min((beat+1)*100, dp[(1<<j)^i]+d[j]));
        }
    }

    cout << dp[(1<<n)-1] << endl;
    
    return 0;
}