#include<iostream>
#include<iomanip>
using namespace std;

int main(){
    double a, b, c;
    cin >> a >> b >> c;
    cout << fixed << setprecision(12) << a/b*c << endl;
    return 0;
}