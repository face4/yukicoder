#include<iostream>
using namespace std;

int rel[50][50] = {};

int main(){
    int m, n, a, b;
    cin >> n >> m;

    for(int i = 0; i < m; i++){
        cin >> a >> b;
        rel[a][b] = rel[b][a] = 1;
    }

    int ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(j == i)  continue;
            for(int k = 0; k < n; k++){
                if(k == i || k == j)    continue;
                for(int l = 0; l < n; l++){
                    if(l == i || l == j || l == k)  continue;
                    bool a = (rel[i][j]+rel[j][k]+rel[k][l]+rel[l][i] == 4);
                    bool b = (rel[i][k] != 1 && rel[j][l] != 1);
                    if(a && b)  ans++; 
                }
            }
        }
    }

    cout << ans/8 << endl;

    return 0;
}