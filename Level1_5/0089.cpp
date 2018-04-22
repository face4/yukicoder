#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

int main(){
    int c, l, r;
    cin >> c >> l >> r;
    double d = (r-l) / 2.0;
    double cal = d*d*M_PI * 2*M_PI*(l+d) * c;
    cout << fixed << setprecision(6) << cal << endl;
    return 0;
}