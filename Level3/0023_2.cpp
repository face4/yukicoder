#include<iostream>
using namespace std;

int main(){
    int h, a, d;
    cin >> h >> a >> d;
    double dp[h+1];
    dp[0] = 0;
    for(int i = 1; i <= h; i++) dp[i] = min(dp[max(0,i-a)]+1, dp[max(0,i-d)]+1.5);
    cout << dp[h] << endl;
    return 0;
}