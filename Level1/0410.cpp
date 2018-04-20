#include<iostream>
#include<iomanip>
using namespace std;

int main(){
    int px,py,qx,qy;
    cin >> px >> py >> qx >> qy;
    cout << fixed << setprecision(1) << ( (abs(px-qx) + abs(py-qy)) / 2.0 ) << endl;
    return 0;
}