#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

int main(){
    cout << fixed << setprecision(12);
    int k;
    cin >> k;
    if(k == 0){
        const double PI = acos(0.0)*2.0;
        cout << PI*PI/6 << endl;
        return 0;
    }
    double d = 0;
    for(int i = 1; i <= k; i++) d += 1.0/i;
    cout << d/k << endl;
    return 0;
}