// 解説を見て感動した
#include<iostream>

using namespace std;

int query(int x, int y){
    cout << x << " " << y << endl << flush;
    cin >> x;
    if(x == 0)  exit(0);

    return x;
}

int main(){
    int a = query(0,0);             // a = X + Y
    int b = query(0,100000);        // b = X + 100000 - Y
    int x = (a+b-100000)/2;         // x = (X+Y+X+Y-100000)/2
    int y = a-x;
    query(x,y);
    return 0;
}