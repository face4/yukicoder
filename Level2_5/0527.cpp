#include<iostream>
#include<algorithm>
using namespace std;
#define printb(x, a, b) if(x) cout << a << endl; else cout << b << endl

int main(){
    int n, v, w, V, sumV = 0;
    static int dp[100001] = {};

    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> v >> w;
        for(int j = 100000; j >= w; j--)    dp[j] = max(dp[j], dp[j-w]+v);
        sumV += v;
    }

    cin >> V;

    int minimum = lower_bound(dp, dp+100001, V) - dp;
    int maximum = upper_bound(dp, dp+100001, V) - 1 - dp;
    
    cout << max(1,minimum) << endl;
    printb(sumV == V, "inf", maximum);
    
    return 0;
}