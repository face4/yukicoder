#include<iostream>
using namespace std;

typedef long long ll;

ll gcd(ll a, ll b){
    return b == 0 ? a : gcd(b, a%b);
}

int main(){
    ll a,b;
    cin >> a >> b;
    ll plus = a+b;
    ll ga = gcd(plus, a);
    plus /= ga;
    ll gb = gcd(plus, b);

    cout << ga*gb << endl;
    return 0;
}