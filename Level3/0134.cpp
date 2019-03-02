#include<iostream>
#include<cstring>
#include<iomanip>
#include<cfloat>
#include<cmath>
using namespace std;

int main(){
    double x, y;
    int n;
    cin >> x >> y >> n;
    double X[n], Y[n], W[n], dp[n][1<<n], sum = 0;
    for(int i = 0; i < n; i++){
        cin >> X[i] >> Y[i] >> W[i];
        sum += W[i];
        for(int j = 0; j < 1<<n; j++)   dp[i][j] = DBL_MAX;
    }
    for(int i = 0; i < n; i++){
        dp[i][1<<i] = (abs(X[i]-x)+abs(Y[i]-y))*(sum+100)/120;
    }  
    for(int s = 0; s < 1<<n; s++){
        double tmps = sum;
        for(int i = 0; i < n; i++){
            if((s>>i)&1)    tmps -= W[i];
        }
        for(int i = 0; i < n; i++){
            if(((s>>i)&1) == 0)    continue;
            for(int j = 0; j < n; j++){
                if((s>>j)&1)    continue;
                dp[j][s|(1<<j)] = min(dp[j][s|(1<<j)], dp[i][s]+(abs(X[j]-X[i])+abs(Y[j]-Y[i]))*(tmps+100)/120);
            }
        }
    }
    double ans = DBL_MAX;
    for(int i = 0; i < n; i++){
        ans = min(ans, dp[i][(1<<n)-1]+(abs(X[i]-x)+abs(Y[i]-y))*100/120);
    }
    cout << fixed << setprecision(12) << ans + sum << endl;
    return 0;
}