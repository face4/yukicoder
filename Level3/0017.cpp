#include<iostream>
#include<queue>
using namespace std;

const int INF = 1<<29;

int main(){
    int n;
    cin >> n;

    int d[n][n], fee[n];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            d[i][j] = i==j ? 0 : INF;
        }
    }

    for(int i = 0; i < n; i++)  cin >> fee[i];

    int m;
    cin >> m;

    int a, b, c;
    for(int i = 0; i < m; i++){
        cin >> a >> b >> c;
        d[a][b] = d[b][a] = c;
    }

    for(int k = 0; k < n; k++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(d[i][k] == INF || d[k][j] == INF)    continue;
                d[i][j] = min(d[i][j], d[i][k]+d[k][j]);
            }
        }
    }

    int ans = INF;
    for(int i = 1; i < n-1; i++){
        for(int j = 1; j < n-1; j++){
            if(i == j)  continue;
            ans = min(ans, d[0][i]+fee[i]+d[i][j]+fee[j]+d[j][n-1]);
        }
    }

    cout << ans << endl;

    return 0;
}