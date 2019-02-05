#include<iostream>
using namespace std;
#define inRange(x,a,b) (a <= x && x <= b)

int main(){
    int y, m, d;
    cin >> y >> m >> d;
    if(inRange(y*10000 + m*100 + d, 19890108, 20190430)) cout << "Yes" << endl;
    else                                                cout << "No" << endl;
    return 0;
}