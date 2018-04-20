#include<iostream>
using namespace std;

int main(){
    int n,h,m,t;
    cin >> n >> h >> m >> t;
    int mins = (n-1) * t;
    m += mins;
    h += m / 60;
    m -=  (m / 60) * 60;
    h %= 24;
    cout << h << endl << m << endl;
    return 0;
}