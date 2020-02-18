#include<iostream>
using namespace std;
typedef long long ll;

int main(){
    ll m;
    cin >> m;
    ll ans = 1;
    for(int i = 0; i < 128; i++){
        (ans *= 2) %= m;
    }
    cout << ans << endl;
    return 0;
}