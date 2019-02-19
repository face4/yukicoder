#include<iostream>
using namespace std;

// 2つ前、1つ前のindex,所持金
int dp[51][51][101] = {};
int l[51], w[51];

bool isK(int a, int b, int c){
    return l[a] != l[b] && l[b] != l[c] && l[c] != l[a] && (l[b]-l[a])*(l[b]-l[c]) > 0;
}

int main(){
    int n, c;
    cin >> n >> c;

    for(int i = 0; i < n; i++)  cin >> l[i];
    for(int i = 0; i < n; i++)  cin >> w[i];

    // initialize
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            for(int k = 0; k < n; k++){
                int cost = w[i]+w[j]+w[k];
                if(isK(i,j,k) && cost <= c){
                    dp[j][k][cost] = max(dp[j][k][cost], l[i]+l[j]+l[k]);
                }
            }
        }
    }

    int ans = 0;
    for(int cost = 0; cost <= c; cost++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(dp[i][j][cost] == 0) continue;
                for(int k = 0; k < n; k++){
                    int ncost = cost + w[k];
                    if(isK(i,j,k) && ncost <= c){
                        dp[j][k][ncost] = max(dp[j][k][ncost], dp[i][j][cost]+l[k]);
                    }
                }
                ans = max(ans, dp[i][j][cost]);
            }
        }
    }

    cout << ans << endl;

    return 0;
}