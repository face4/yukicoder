#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
#define equals(a,b) (fabs(a-b) < 1e-13)

int main(){
    cout << fixed << setprecision(15);
    long double a, b, c;
    cin >> a >> b >> c;
    if(a == 0){
        if(b == 0){
            cout << (c==0 ? -1 : 0) << endl;
        }else{
            cout << 1 << endl << -c/b << endl;
        }
    }else{
        long double d = b*b-4*a*c;
        if(d < 0){
            cout << 0 << endl;
        }else if(equals(d,0)){
            cout << 1 << endl << -b/a/2 << endl;
        }else{
            long double f = sqrt(d);
            // :(
            long double x = (-b + (b<0 ? f : -f))/2/a;
            long double y = c/a/x;
            if(x > y)   swap(x,y);
            cout << 2 << endl;
            cout << x << endl << y << endl;
        }
    }
    return 0;
}