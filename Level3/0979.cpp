#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> dp(300001, 0);
    for(int s = 0; s < n; s++){
        int x;  cin >> x;
        for(int i = 1; i*i <= x; i++){
            if(x%i) continue;
            int j = x/i;
            if(j < x)   dp[x] = max(dp[j]+1, dp[x]);
            j = i;
            if(j < x)   dp[x] = max(dp[j]+1, dp[x]);
        }
        dp[x] = max(dp[x], 1);
    }
    cout << *max_element(dp.begin(),dp.end()) << endl;
    return 0;
}