#include<iostream>
using namespace std;

int main(){
    double p, q;
    cin >> p >> q;
    cout << ((1-p) < p*(1-q) ? "YES" : "NO") << endl;
    return 0;
}