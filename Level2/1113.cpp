#include<iostream>
#include<cmath>
using namespace std;

typedef long long ll;

ll gcd(ll a, ll b){
    return b == 0 ? a : gcd(b, a%b);
}

int main(){
    ll a, b;
    cin >> a >> b;
    ll g = gcd(a, b);
    ll s = sqrt(g);
    cout << (s*s==g ? "Odd" : "Even") << endl;
    return 0;
}