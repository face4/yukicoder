#include<iostream>
#include<iomanip>
using namespace std;

typedef long double ld;

int main(){
    int p,c;
    cin >> p >> c;
    ld prime = 41.0/6;
    ld nonprime = 49.0/6;
    ld ans = 1;
    for(int i = 0; i < p; i++)  ans *= prime;
    for(int i = 0; i < c; i++)  ans *= nonprime;
    cout << fixed << setprecision(9) << ans << endl;
    return 0;
}