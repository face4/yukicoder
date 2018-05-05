#include<iostream>
using namespace std;

typedef long long ll;

int main(){
    ll b1, b2, b3;
    cin >> b1 >> b2 >> b3;

    cout << (b3*b3-b2*b3+b2*b2-b1*b3)/(b2-b1) << endl;
    return 0;
}