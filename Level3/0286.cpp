#include<iostream>
#include<climits>
using namespace std;

const int INF = 1<<29;

int main(){
    int n;
    cin >> n;

    int m[n];
    for(int i = 0; i < n; i++)  cin >> m[i];

    int dp[1<<n];
    dp[0] = 0;
    for(int i = 1; i < 1<<n; i++){
        dp[i] = INF;
    }

    for(int bit = 0; bit < 1<<n; bit++){
        int teika = 0;
        for(int j = 0; j < n; j++)  if(bit & (1<<j))    teika += m[j];
        teika %= 1000;
        for(int j = 0; j < n; j++){
            if(bit & (1<<j))  continue;
            dp[bit|(1<<j)] = min(dp[bit|(1<<j)], dp[bit] + max(0, m[j]-teika));
        }
    }

    cout << dp[(1<<n)-1] << endl;

    return 0;
}
