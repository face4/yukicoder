#include<iostream>
using namespace std;

int main(){
    int x, y, vx, vy;
    cin >> x >> y >> vx >> vy;
    cout << max(x,y) + (x > vx && x == y && vx == vy ? 1 : 0) << endl;
    return 0;
}