#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> v(11, 1<<30);
    v[0] = 0;
    int x;
    for(int i = 0; i <= n; i++){
        vector<int> dp = v;
        for(int j = 0; j < 11; j++) dp[j] = v[j]+1;
        cin >> x;
        for(int to = 1; to <= x; to++){
            for(int j = 0; j < to; j++){
                for(int k = 0; j+k+1 <= to; k++){
                    dp[j+k+1] = min(dp[j+k+1], dp[j]+dp[k]);
                }
            }
        }
        v = dp;
    }
    for(int i = 0; i <= x; i++) cout << v[i] << " \n"[i==x];
    return 0;
}