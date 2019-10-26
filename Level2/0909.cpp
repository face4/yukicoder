#include<iostream>
using namespace std;
typedef long long ll;

int main(){
    int n;
    cin >> n;
    ll x[n], y[n];
    for(int i = 0; i < n; i++)  cin >> x[i];
    for(int i = 0; i < n; i++)  cin >> y[i];
    ll ans = 1e18;
    for(int i = 0; i < n; i++)  ans = min(ans, x[i]+y[i]);
    cout << ans << endl;
    cout << 0 << endl;
    for(int i = 0; i < n; i++){
        cout << min(ans,x[i]) << endl;
    }
    cout << ans << endl;
    return 0;
}