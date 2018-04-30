#include<iostream>
using namespace std;

int main(){
    int x, y;
    cin >> x >> y;
    if(x == y)                  cout << 0 << endl;
    else if(x == 0)             cout << 2 << endl;
    else if(y == 0)             cout << 1 << endl;
    else if(abs(x) == abs(y))   cout << 3 << endl;
    else                        cout << -1 << endl;

    return 0;
}