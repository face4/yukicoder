#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

int main(){
    cout << fixed << setprecision(6);
    int a, b;
    cin >> a >> b;
    if(a == b)  cout << sqrt(a*a + b*b) << endl;
    else        cout << sqrt( max(a,b)*max(a,b) - min(a,b)*min(a,b) ) << endl;
    return 0;
}