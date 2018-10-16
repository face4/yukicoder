#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

int main(){
    double r, d;
    cin >> r >> d;
    cout << fixed << setprecision(10) << sqrt(d*d-r*r) << endl;
    return 0;
}