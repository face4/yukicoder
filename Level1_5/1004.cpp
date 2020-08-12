/// ?
#include<iostream>
using namespace std;

typedef long long ll;

int main(){
    ll a, b, x, n;
    cin >> a >> b >> x >> n;
    ll c = n/2, d = 0;
    if(x%2==0)  swap(c, d);
    cout << c << " " << d << endl;
    return 0;
}