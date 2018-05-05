#include<iostream>
using namespace std;
typedef long long ll;

ll gcd(ll a, ll b){
    return b == 0 ? a : gcd(b, a%b);
}

ll lcm(ll a, ll b){
    return a*b/gcd(a,b);
}

int main(){
    ll n, d;
    cin >> n >> d;
    cout << lcm(n,d)/d-1 << endl;
    return 0;
}