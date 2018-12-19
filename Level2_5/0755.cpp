#include<iostream>
using namespace std;
#define inRange(x,a,b) (a <= x && x <= b)

typedef long long ll;

int main(){
    int n, m;
    cin >> n >> m;

    ll mat[131][131] = {};

    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= m; j++){
            cin >> mat[i][j];
        }
    }

    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= m; j++){
            mat[i][j] += mat[i-1][j] + mat[i][j-1] - mat[i-1][j-1];
        }
    }

    int x[n], y[n];
    for(int i = 0; i < n; i++)  cin >> x[i] >> y[i];
    int ans[10] = {};

    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= m; j++){
            for(int ni = i; ni <= m; ni++){
                for(int nj = j; nj <= m; nj++){
                    ll tmp = mat[ni][nj] + mat[i-1][j-1] - mat[i-1][nj] - mat[ni][j-1];
                    if(tmp != 0)    continue;
                    for(int k = 0; k < n; k++){
                        if(inRange(x[k], i, ni) && inRange(y[k], j, nj))    ans[k]++;
                    }
                }
            }
        }
    }

    for(int i = 0; i < n; i++)  cout << ans[i] << endl;

    return 0;
}