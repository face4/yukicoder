#include<iostream>
#include<iomanip>
using namespace std;

int main(){
    double p, q;
    cin >> p >> q;
    cout << fixed << setprecision(12) << 
        100 * p*q / (2*p*q + 10000 - 100*q - 100*p) << endl;
    return 0;
}