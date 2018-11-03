#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;

    int dp[1<<n];
    memset(dp, 0, sizeof(dp));

    int a[m], b[m], c[m];
    for(int i = 0; i < m; i++)  cin >> a[i] >> b[i] >> c[i];

    for(int i = 1; i < 1<<n; i++){
        for(int j = 0; j < n; j++){
            int tmp = 0;
            if(~i & (1<<j))  continue;
            int bef = i ^ (1<<j);
            for(int k = 0; k < m; k++){
                if(b[k] != j)   continue;
                if(1<<(a[k]) & bef) tmp += c[k];
            }
            dp[i] = max(dp[i], dp[bef] + tmp);
        }
    }

    cout << *max_element(dp, dp+(1<<n)) << endl;

    return 0;
}