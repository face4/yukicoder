#include<iostream>
#include<iomanip>
using namespace std;

int main(){
    double vl, vr, d, w;
    cin >> vl >> vr >> d >> w;

    cout << fixed << setprecision(7) << d/(vl+vr)*w << endl;
    return 0;
}