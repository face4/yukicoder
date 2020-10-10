#include<iostream>
#include<iomanip>
using namespace std;

int main(){
    double a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;
    double x = (c*e-b*f) / (a*e-b*d);
    double y = (c-a*x) / b;
    cout << fixed << setprecision(12) << x << " " << y << endl;
    return 0;
}