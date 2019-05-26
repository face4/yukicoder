#include<iostream>
using namespace std;

int main(){
    int l, r, m;
    cin >> l >> r >> m;
    if(r-l+1 >= m)  cout << m << endl;
    else            cout << r-l+1 << endl;
    return 0;
}