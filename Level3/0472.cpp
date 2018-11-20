#include<iostream>
#include<vector>
#include<iomanip>
using namespace std;

typedef long long ll;

const ll INF = 1ll<<60;

int main(){
    int n, p;
    cin >> n >> p;

    vector<ll> dp(3*n+5, INF);
    dp[0] = 0;
    
    int a, b, c;

    for(int i = 0; i < n; i++){
        vector<ll> next(3*n+5, INF);
        cin >> a >> b >> c;
        for(int j = 0; j <= 3*n; j++){
            if(dp[j] != INF){
                next[j] = min(next[j], dp[j] + a);
                next[j+1] = min(next[j+1], dp[j] + b);
                next[j+2] = min(next[j+2], dp[j] + c);
                next[j+3] = min(next[j+3], dp[j] + 1);
            }
        }
        dp = next;
    }

    cout << fixed << setprecision(10) << (double)(dp[p]) / n << endl;
    return 0;
}