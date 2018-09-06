#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

#define PI acos(0.0)*2.0

int main(){
    double a, b;
    cin >> a >> b;
    cout << fixed << setprecision(8) << 2*PI*(b-a) << endl;
    return 0;
}