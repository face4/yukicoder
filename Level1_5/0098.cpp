#include<iostream>
#include<cmath>
using namespace std;

int main(){
    int x,y;
    cin >> x >> y;
    double d = 2 * sqrt(x*x + y*y);
    cout << (int)d + 1 << endl;
    return 0;
}