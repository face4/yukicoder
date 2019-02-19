#include<iostream>
#include<cmath>
using namespace std;

double ginv(double x){
    return 800 * log2(x);
}

double g(double x){
    return pow(2.0, x/800);
}

int main(){
    int n;
    cin >> n;

    double a[101] = {}, b[101] = {};
    a[0] = b[0] = 1;
    for(int i = 1; i < 101; i++)    a[i] = a[i-1]*0.9, b[i] = b[i-1]*0.81;
    double finf = 1.0 / sqrt(19);

    auto f = [&](int k) -> double{
        double s = 0, t = 0;
        for(int i = 1; i <= k; i++) s += b[i], t += a[i];
        s = sqrt(s);
        double u = s/t-finf;
        double v = sqrt(b[1])/a[1]-finf;
        return u * 1200 / v;
    };

    double s = 0, t = 0, r;
    for(int i = 1; i <= n; i++){
        cin >> r;
        s += g(r) * a[i];
        t += a[i];
    }

    double ans = ginv(s/t)-f(n);

    cout << round(ans) << endl;

    return 0;
}