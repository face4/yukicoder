#include<iostream>
#include<iomanip>
using namespace std;

// 実行可能領域の頂点だけ調べればよい？
int main(){
    double c, d;
    cin >> c >> d;
    auto f = [=](double x, double y)->double{
        return 1000*x + 2000*y;
    };
    double ans = max(f(0, min(7*d/5, 7*c/2)), f(min(4*c/3, 4*d), 0));
    double a = (20*c-8*d)/13, b = (21*d-7*c)/13;
    if(a >= 0 && b >= 0)  ans = max(ans, f((20*c-8*d)/13, (21*d-7*c)/13));
    cout << fixed << setprecision(12) << ans << endl;
    return 0;
}