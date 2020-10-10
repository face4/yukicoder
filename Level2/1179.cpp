#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

int main(){
    double a, b, c;
    cin >> a >> b >> c;
    double d = b*b-4*a*c;
    cout << fixed << setprecision(12);
    if(d < 0){
        cout << "imaginary" << endl;
    }else if(d == 0){
        cout << -b/2/a << endl;
    }else{
        d = sqrt(d);
        double y, z;
        if(-b < 0)  y = (-b-d)/2/a;
        else        y = (-b+d)/2/a;
        z = c/a/y;
        if(y > z)   swap(y, z);
        cout << y << " " << z << endl;
    }
    return 0;
}