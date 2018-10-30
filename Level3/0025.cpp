#include<iostream>
using namespace std;
typedef long long ll;

ll gcd(ll a, ll b){
    return b == 0 ? a : gcd(b, a%b);
}

int main(){
    ll n, m;
    cin >> n >> m;

    ll g = gcd(n, m);
    n /= g;
    m /= g;

    int two = 0, five = 0;

    while(m % 2 == 0)   two++, m /= 2;
    while(m % 5 == 0)   five++, m /= 5;

    if(m != 1){
        n = -1;
    }else{
        while(n % 10 == 0)  n /= 10;
        n %= 10;
        while(two > five)   five++, n *= 5, n %= 10;
        while(five > two)   two++, n *= 2, n %= 10;
    }

    cout << n << endl;

    return 0;
}