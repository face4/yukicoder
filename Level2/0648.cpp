#include<iostream>
#include<cmath>
using namespace std;

int main(){
    long long n;
    cin >> n;
    n *= 2;
    long long s = sqrt(n);
    if(s*(s+1) == n)    cout << "YES" << endl << s << endl;
    else                cout << "NO" << endl;
    return 0;
}