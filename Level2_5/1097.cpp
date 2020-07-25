#include<iostream>
using namespace std;
typedef long long ll;

ll db[50][100000] = {}; // 40~overflowするかもしれないけどどうせ使わないからいい

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)  cin >> db[0][i];
    for(int i = 1; i < 50; i++){
        for(int j = 0; j < n; j++){
            db[i][j] = db[i-1][j] + db[i-1][(j+db[i-1][j])%n];
        }
    }
    int q;
    cin >> q;
    while(q--){
        ll k;
        cin >> k;
        int pos = 0;
        ll ans = 0;
        for(int i = 0; i < 50; i++){
            if(k>>i&1)  ans += db[i][pos], pos = (pos+db[i][pos]%n)%n;
        }
        cout << ans << endl;
    }
    return 0;
}