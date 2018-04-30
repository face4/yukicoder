// long long の modを取るとintになってしまう
// modを取る数をlong long にしても意味なし
// 仕方なくmodを取った結果を新しいlong long型整数に代入して対応
#include<iostream>
using namespace std;

typedef long long ll;

int main(){
    ll n;
    ll ans;
    ll mod = 1000007;

    cin >> n;
    n += 2;

    ll A = (n/2)%mod;
    ll B = (n/2 + 1)%mod;
        
    if(n % 2 == 1){
        ans = (A*B)%mod - 1;
    }else{
        ans = (A*A)%mod - 1;
    }

    if(ans < 0) ans += mod;

    cout << ans << endl;
    return 0;
}