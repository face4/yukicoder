#include<iostream>
#include<numeric>
using namespace std;
typedef long long ll;

int main(){
    int n;
    cin >> n;
    int x[n];
    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        x[i] = b-a;
    }
    ll ans = accumulate(x, x+n, 0ll);
    ll lef = 0, rig = ans;
    for(int i = 0; i < n; i++){
        lef += -x[i];
        rig -= x[i];
        ans = max(ans, lef+rig);
    }
    cout << ans << endl;
    return 0;
}