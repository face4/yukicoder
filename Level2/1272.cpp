#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

int main(){
    double d = 0;
    int k;
    cin >> k;
    if(k == 0){
        cout << 0 << endl;
        return 0;
    }
    for(int i = 1; i <= 9; i++){
        double tmp = sin(i*k);
        for(int j = 1; j <= i; j++) tmp /= i;
        d += tmp;
    }
    cout << fixed << setprecision(12) << d << endl;
    return 0;
}