#include<iostream>
#include<iomanip>
using namespace std;

typedef long double ld;

int main(){
    ld xa, ya, xb, yb;
    cin >> xa >> ya >> xb >> yb;

    ld ans = xa * (yb-ya) / (xa+xb) + ya;
    cout << fixed << setprecision(6) << ans << endl;
    return 0;
}