#include<iostream>
#include<cmath>
using namespace std;

int main(){
    int x, y, r;
    cin >> x >> y >> r;
    cout << ceil(abs(x)+abs(y)+sqrt(2)*r) << endl;
    return 0;
}