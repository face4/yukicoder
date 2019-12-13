#include<iostream>
#include<cmath>
using namespace std;

#define PI (2*acos(0.0))

int main(){
    double r, R;
    cin >> r >> R;
    double t = 2*PI-2*fabs(asin(r/R));
    cout << t << endl << r*(2*R*t+PI*r) << endl;
    return 0;
}