#include<iostream>
using namespace std;

int main(){
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    x--; y--;
    x %= m*2;
    y %= m*2;
    if(x >= m)   x = m - 1 - x%m;
    if(y >= m)   y = m - 1 - y%m;
    if(x == y)  cout << "YES" << endl;
    else        cout << "NO" << endl;

/* 頭悪い
    bool proceed = true;
    while(x > m){
        x -= m;
        proceed = !proceed;
    }

    if(!proceed)    x = m-x+1;

    proceed = true;
    while(y > m){
        y -= m;
        proceed = !proceed;
    }

    if(!proceed)    y = m-y+1;

    if(x == y)  cout << "YES" << endl;
    else        cout << "NO" << endl;
*/
    return 0;
}