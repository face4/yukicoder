#include<iostream>
using namespace std;

int main(){
    int n;
    cin >> n;

    int a[n];
    for(int i = 0; i < n; i++)  cin >> a[i];

    int dp[1<<14] = {};

    for(int i = 0; i < 1<<n; i++){
        for(int j = 0; j < n; j++){
            for(int k = j+1; k < n; k++){
                if(~i&(1<<j) && ~i&(1<<k))
                    dp[i|1<<j|1<<k] = max(dp[i|1<<j|1<<k], dp[i] + (a[j]^a[k]));
            }
        }
    }

    cout << dp[(1<<n)-1] << endl;

    return 0;
}