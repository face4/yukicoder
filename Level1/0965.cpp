// ?
#include<iostream>
using namespace std;
typedef long long ll;

int main(){
    ll a, b, c;
    cin >> a >> b >> c;
    ll tmp = min(abs(b-a), min(abs(c-a), abs(c-b)));
    cout << tmp << endl;
    return 0;
}