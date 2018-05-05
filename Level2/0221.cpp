#include<iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    double ans = (10000.0-n)*100.0/(10000.0+98.0*n);
    cout << ans << endl;
    return 0;
}