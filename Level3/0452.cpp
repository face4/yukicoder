#include<iostream>
#include<set>
#include<vector>
using namespace std;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    int c[m][n][n];
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n*n; j++){
            cin >> c[i][j/n][j%n];
        }
    }
    set<int> s[m][2*n+2];
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            s[i][2*n].insert(c[i][j][j]);
            s[i][2*n+1].insert(c[i][n-1-j][j]);
        }
        for(int j = 0; j < n; j++){
            for(int k = 0; k < n; k++){
                s[i][j].insert(c[i][j][k]);
                s[i][n+j].insert(c[i][k][j]);
            }
        }
    }
    // O(M^2 N^3)
    int ans = 2*n;
    vector<bool> v(n*n*m+1,0);
    for(int i = 0; i < m; i++){
        for(int j = i+1; j < m; j++){
            for(int k = 0; k < 2*n+2; k++){
                for(int l = 0; l < 2*n+2; l++){
                    for(int x : s[i][k])    v[x] = true;
                    int dbl = 0;
                    for(int x : s[j][l])    dbl += v[x];
                    ans = min(ans, (n-dbl)*2+dbl-1);
                    for(int x : s[i][k])    v[x] = false;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}