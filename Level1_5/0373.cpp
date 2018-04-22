#include<iostream>
using namespace std;

typedef long long ll;

int main(){
    ll a,b,c,d;
    cin >> a >> b >> c >> d;
    ll ans = (((a%d)*(b%d))%d*(c%d))%d;
    cout << ans << endl;
    return 0;
}