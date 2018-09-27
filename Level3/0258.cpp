#include<iostream>
#include<set>
#include<algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;

    int dp[n+1], v[n+1];
    dp[0] = 0, v[0] = 0;
    cin >> v[1];

    dp[1] = v[1];
    for(int i = 2; i <= n; i++){
        cin >> v[i];
        dp[i] = max(dp[i-1], dp[i-2]+v[i]);
    }

    set<int> ans;
    for(int i = n; i >= 1; i--){
        if(dp[i] != dp[i-1]){
            ans.emplace(i);
            int next = dp[i]-v[i];
            while(dp[i] != next)    i--;
            i++;
        }
    }

    cout << dp[n] << endl;
    set<int>::iterator it = ans.begin();
    for(int i = 0; i < ans.size(); i++, it++){
        cout << *it << " \n"[i+1 == ans.size()];
    }
    
    return 0;
}