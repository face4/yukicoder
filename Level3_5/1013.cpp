#include<iostream>
using namespace std;

typedef long long ll;

int main(){
    int n, k;
    cin >> n >> k;
    ll p[n];
    for(int i = 0; i < n; i++)  cin >> p[i];
    ll db[40][n];
    for(int i = 0; i < n; i++)  db[0][i] = p[i];
    for(int i = 1; i < 33; i++){
        for(int j = 0; j < n; j++){
            db[i][j] = db[i-1][j]+db[i-1][(j+db[i-1][j])%n];
        }
    }
    for(int i = 0; i < n; i++){
        ll ans = i;
        for(int x = 0; x < 32; x++){
            if(k>>x&1)  ans += db[x][ans%n];
        }
        cout << ans+1 << endl;
    }
    return 0;
}