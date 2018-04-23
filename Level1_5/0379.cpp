#include<iostream>
#include<iomanip>
using namespace std;

int main(){
    long long n, g, v;
    cin >> n >> g >> v;
    cout << fixed << setprecision(11) <<((long double)(n/5) * g / v) << endl;
    return 0;
}