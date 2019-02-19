// 6桁硬貨の枚数を決めると1円硬貨の枚数は自動で決まる
// 額を111111で割った商を任意個の1~9を組み合わせて表す通り数
// をdpで求め、その累積和を取る
#include<iostream>
#include<vector>
using namespace std;

typedef long long ll;
const ll mod = 1e9 + 9;

int main(){
    vector<ll> dp(90001, 0);
    dp[0] = 1;
    for(int i = 1; i <= 9; i++){
        for(int j = 0; j+i < 90001; j++){
            dp[j+i] += dp[j];
            dp[j+i] %= mod;
        }
    }

    for(int i = 1; i < 90001; i++)  dp[i] += dp[i-1], dp[i] %= mod;

    int t;
    cin >> t;

    ll m;
    while(t-- > 0){
        cin >> m;
        cout << dp[m/111111ll] << endl;
    }

    return 0;
}