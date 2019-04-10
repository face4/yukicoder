#include<iostream>
using namespace std;

int main(){
    double c1, c2, c3, c4;
    cin >> c1 >> c2 >> c3 >> c4;
    double x = (c2*c3-c1*c4) / (c2*c2-c1*c3);
    double y = (c3*c3-c2*c4) / (c2*c2-c1*c3);
    cout << (x*x-4*y < 0 ? "I" : "R") << endl;
    return 0;
}