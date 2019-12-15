#include<iostream>
#include<iomanip>
using namespace std;

int main(){
    long double x;
    cin >> x;
    long double ans = 0;
    for(int i = 1; i <= 1000000; i++){
        ans += 1.0/(x+i)/(x+i);
    }
    // 解説を読んだ、適当な項(1000000)までは愚直に計算して、
    // そこから先の和を積分して適当に足しこんでやる
    // \int_{n+1}^{infinity} (x+y)^{-2} = f(infinity)-f(n+1) = 1/(x+n+1)
    // f(y) = -(x+y)^{-1}
    cout << fixed << setprecision(12) << ans+1.0/(x+1000000+1) << endl;
    return 0;
}