// kmjpさんの解説を読んだ
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

int main(){
    int n, m;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++)  cin >> a[i];
    cin >> m;
    int b[m];
    for(int i = 0; i < m; i++)  cin >> b[i];
    sort(b, b+m);
    reverse(b, b+m);
    
    int sum[1<<n];
    for(int i = 0; i < 1<<n; i++){
        sum[i] = 0;
        for(int j = 0; j < n; j++){
            if((i>>j)&1)    sum[i] += a[j];
        }
    }
    // dp[i][j] := 大きい方からi個の箱を用いてビット列j
    //             が表すおもちゃ集合を格納出来るか否か
    bool dp[m+1][1<<n];
    memset(dp, 0, sizeof(dp));
    dp[0][0] = true; // 初期状態.dp[x(x >= 1)][y]を更新していく

    // O(m * 2^n * 2^n)
    for(int i = 0; i < m; i++){
        for(int s1 = 0; s1 < 1<<n; s1++){
            for(int s2 = 0; s2 < 1<<n; s2++){
                if(!dp[i][s1] || sum[s2] > b[i] || (s1&s2))  continue;
                dp[i+1][s1|s2] = true;
            }
        }
        if(dp[i+1][(1<<n)-1]){
            cout << i+1 << endl;
            return 0;
        }
    }

    cout << -1 << endl;
    return 0;
}