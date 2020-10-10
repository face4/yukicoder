#include<iostream>
using namespace std;

int main(){
    double a, b;
    cin >> a >> b;
    if(a >= 12)  a -= 12;
    a = (a*60 + b)*0.5;
    b = b*6;
    if(b > a)   a += 360;
    cout << (int)(1e-6+(a-b)/(360.0/(60*60)-360.0/(60*60*12))) << endl;
    return 0;
}