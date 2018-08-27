#include<iostream>
using namespace std;

int dp[1000001] = {};

int main(){
    int n;
    cin >> n;

    int x[n];
    for(int i = 0; i < n; i++)  cin >> x[i];

    for(int i : x)  dp[i] = 1;

    int ans = 0;
    for(int i = 1; i < 1000001; i++){
        if(!dp[i])   continue;
        for(int j = i+i; j < 1000001; j += i){
            if(dp[j])   dp[j] = max(dp[j], dp[i]+1);
        }
        ans = max(ans, dp[i]);
    }

    cout << ans << endl;

    return 0;
}