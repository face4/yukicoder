#include<iostream>
#include<iomanip>
using namespace std;

int main(){
    int a, b, x, y;
    cin >> a >> b >> x >> y;
    double ans = (a+b) * min((double)x/a,(double)y/b);
    cout << fixed << setprecision(7) << ans << endl;
    return 0;
}