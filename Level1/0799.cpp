#include<iostream>
using namespace std;
typedef long long ll;
#define inRange(x,a,b) (a <= x && x <= b)

int main(){
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    ll ans = 0;
    for(int i = a; i <= b; i++){
        ans += (d-c+1);
        if(inRange(i, c, d))    ans--;
    }
    cout << ans << endl;
    return 0;
}