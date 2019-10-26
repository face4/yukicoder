#include<iostream>
#include<iomanip>
using namespace std;

int main(){
    int n;
    cin >> n;
    double d = 2, sum = 2;
    for(double i = 3; i <= n; i++){
        d += 2/i + sum/i/((i-1)*(i-2)/2)*(i-2);
        for(int j = 1; j < i; j++)  sum += i*j;
    }
    cout << fixed << setprecision(12) << d << endl;
    return 0;
}