#include<iostream>
using namespace std;
typedef long long ll;

ll gcd(ll a, ll b){
    return b == 0 ? a : gcd(b, a%b);
}

const ll ma = 1e18;

ll lcm(ll a, ll b){
    ll tmp = a/gcd(a, b);
    if(b > ma/tmp)  return -1;
    return tmp*b;
}

int main(){
    ll t, a, b;
    cin >> t >> a >> b;
    t--;
    ll g = lcm(a, b);
    if(g == -1){
        cout << t/a+t/b+1 << endl;
    }else{
        cout << t/a-t/g+t/b+1 << endl;
    }
    return 0;
}