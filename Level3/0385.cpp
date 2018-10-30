#include<iostream>
#include<algorithm>
using namespace std;

bool isPrime(int x){
    if(x == 2)  return true;
    for(int i = 2; i*i <= x; i++)   if(x % i == 0)  return false;
    return true;
}

int main(){
    int m, n;
    cin >> m >> n;

    int c[n];
    for(int i = 0; i < n; i++)  cin >> c[i];

    int dp[m+1];
    for(int i = 0; i < m; i++)  dp[i] = -1;
    dp[m] = 0;

    for(int i = 0; i < n; i++){
        for(int j = m-c[i]; j >= 0; j--){
            if(dp[j+c[i]] == -1) continue;
            dp[j] = max(dp[j], dp[j+c[i]]+1);
        }
    }

    int ans = 0;
    for(int i = 2; i < m; i++){
        if(dp[i] == -1) continue;
        if(isPrime(i))  ans += dp[i];
    }

    ans += m / *min_element(c, c+n);

    cout << ans << endl;

    return 0;
}