#include<iostream>
#include<iomanip>
using namespace std;

int main(){
    double a, b;
    cin >> a >> b;
    if(a > b)   swap(a, b);
    auto f = [&](double x){
        return 1.0/3.0*x*x*x-(a+b)/2*x*x+a*b*x;
    };
    cout << fixed << setprecision(12) << -(f(b)-f(a)) << endl;
    return 0;
}