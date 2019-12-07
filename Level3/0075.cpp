// kmjpさんのブログを読んだ
// kに到達するまでに振った回数の期待値を仮定してdpする
// dp[k] = kに到達するまでに振った回数の期待値　が仮定した値以上なら
// 求めたい答えは仮定値より上
// 仮定値の変動とdp[k]の変動は明らかに仮定値の変動の方が大きいので
// dp[k] >= 仮定値なら仮定値を上げてやる
// dp[k] >= 仮定値のときに仮定値を下げると更に差が開いてしまう
#include<iostream>
#include<iomanip>
#include<vector>
using namespace std;

double f(int k, double d){
    vector<double> dp(k+1, 0);
    for(int i = 1; i <= k; i++){
        for(int j = 1; j <= 6; j++){
            dp[i] += j <= i ? dp[i-j] : d;
        }
        dp[i] = dp[i] / 6 + 1;
    }
    return dp[k];
}

// accepted 192ms
int main(){
    int k;
    cin >> k;
    double d = 0;
    for(int i = 0; i < 100000; i++){
        int acc = 0;
        while(acc != k){
            if(acc > k) acc = 0;
            acc += rand()%6+1;
            d++;
        }
    }
    cout << d/100000 << endl;
    return 0;
}

// accepted 5ms
int binarySearch(){
    int k;
    cin >> k;
    double l = 0, r = 1e9;
    for(int i = 0; i < 100; i++){
        double mid = (l+r)/2;
        if(f(k, mid) >= mid)  l = mid;
        else                  r = mid;
    }
    cout << fixed << setprecision(12) << l << endl;
    return 0;
}