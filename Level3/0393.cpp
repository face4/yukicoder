#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t-- > 0){
        int a, b;
        cin >> a >> b;
        if(a > b)   swap(a, b);
        int m;
        cin >> m;
        vector<int> v(m);
        for(int i = 0; i < m; i++)  cin >> v[i];
        sort(v.begin(), v.end());
        vector<bool> dp(max(a,b)+1, 0);
        dp[0] = true;
        int ans = 0, sum = 0;
        for(int i = 0; i < m; i++){
            sum += v[i];
            if(sum > a+b)   break;
            for(int j = max(a,b); j-v[i] >= 0; j--){
                if(dp[j-v[i]])  dp[j] = true;
            }
            int k;
            for(k = a; k >= 0; k--){
                if(dp[k])   break;
            }
            if(k < 0)   break;
            if(b-(sum-k) < 0) break;
            ans = i+1;
        }
        cout << ans << endl;
    }
    return 0;
}