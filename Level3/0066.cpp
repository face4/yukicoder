#include<iostream>
#include<vector>
#include<iomanip>
using namespace std;

double win(double x, double y){
    return x*x/(x*x+y*y);
}

int main(){
    int m;
    cin >> m;
    double s[1<<m];
    for(int i = 0; i < 1<<m; i++)   cin >> s[i];
    vector<vector<double>> dp(m+1, vector<double>(1<<m, 0.0));
    fill(dp[0].begin(), dp[0].end(), 1.0);
    for(int r = 1; r <= m; r++){
        for(int j = 0; j < 1<<m; j++){
            int from;
            if(j%(1<<r) < 1<<(r-1)) from = j/(1<<r)*(1<<r)+(1<<(r-1));
            else                    from = j/(1<<r)*(1<<r);
            for(int k = 0; k < 1<<(r-1); k++){
                dp[r][j] += dp[r-1][j]*dp[r-1][from+k]*win(s[j],s[from+k]);
            }
        }
    }
    cout << fixed << setprecision(12) << dp[m][0] << endl;
    return 0;
}
