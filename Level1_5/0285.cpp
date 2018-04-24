#include<iostream>
#include<iomanip>
using namespace std;

int main(){
    long long d;
    cin >> d;
    cout << fixed << setprecision(2) << (d / 100.0 * 108.0) << endl;
    return 0;
}