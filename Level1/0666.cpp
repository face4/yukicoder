#include<iostream>
using namespace std;
typedef long long ll;

int main(){
    ll a, b;
    cin >> a >> b;
    ll c = (a*b) % 1000000007;
    cout << c << endl;
    return 0;
}