// O(sqrt(n)*sqrt(n)) = O(n)?
#include<iostream>
using namespace std;
typedef long long ll;

int main(){
    ll n;
    cin >> n;

    ll a = n-1, b = n-1;

    for(ll i = 1; i*i <= n; i++){
        if(n%i) continue;

        for(ll j = 1; j*j <= i; j++){
            if(i%j == 0) a = min(a, j-1 + i/j-1 + n/i-1);
        }

        for(ll j = 1; j*j <= n/i; j++){
            if((n/i)%j == 0)    a = min(a, j-1 + (n/i)/j-1 + i-1);
        }
    }

    cout << a << " " << b << endl;
    return 0;
}