#include<iostream>
#include<cstring>
using namespace std;

typedef long long ll;

int main(){
    int n;
    cin >> n;
    int c[n][n];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> c[i][j];
        }
    }
    
    ll dp[n][1<<n][1<<n];
    memset(dp, 0x3f, sizeof(dp));

    for(int i = 0; i < n; i++){
        dp[i][0][1<<i] = 0;
    }

    ll ans = 1ll<<60;
    for(int flip = 0; flip < 1<<n; flip++){
        for(int white = 0; white < 1<<n; white++){
            for(int i = 0; i < n; i++){
                if((white>>i&1) == 0) continue;
                for(int j = 0; j < n; j++){
                    if(white>>j&1)  continue;
                    ll nc = dp[i][flip][white] + c[i][j];
                    int nwhite = white^(1<<j);
                    int nflip = flip;
                    if((flip>>i&1) == 0){
                        nwhite ^= 1<<i;
                        nflip ^= 1<<i;
                    }else if(nwhite == (1<<n)-1){
                        ans = min(ans, nc);
                    }
                    dp[j][nflip][nwhite] = min(dp[j][nflip][nwhite], nc);
                }
            }
        }
    }

    cout << ans << endl;
    return 0;
}