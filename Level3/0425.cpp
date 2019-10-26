#include<iostream>
#include<iomanip>
using namespace std;

double dp[101][101] = {};

int main(){
    int p, q;
    cin >> p >> q;
    dp[0][p] = 1.0/3.0; // 1回目のじゃんけんで勝つ確率は1/3
    double r = 1.0/3.0;
    for(int i = 0; i < 100; i++){
        for(int j = 0; j <= 100; j++){
            // 確率jで必勝法を使う
            // 必勝法を使う場合、次のあいこで必勝法を使う確率はmax(0,j-q)%
            // あいこになる確率はdp[i][j]*j/100/2, 勝つ確率もdp[i][j]*j/100/2
            // 必勝法を使わない場合、次のあいこで必勝法を使う確率はmin(100,j+q)%
            // 必勝法を使わないと普通のじゃんけんなので、あいこ、勝ち、負けともに
            // 確率はdp[i][j]*(100-j)/100/3
            dp[i+1][max(0,j-q)] += dp[i][j]*j/100.0/2.0;
            dp[i+1][min(100,j+q)] += dp[i][j]*(100-j)/100.0/3.0;
            r += dp[i][j]*j/100.0/2.0;
            r += dp[i][j]*(100-j)/100.0/3.0;
        }
    }
    cout << fixed << setprecision(12) << r << endl;
    return 0;
}