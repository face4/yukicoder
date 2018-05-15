#include<iostream>
#include<cmath>
using namespace std;

typedef long long ll;

bool isPrime(ll a){
    for(ll i = 2; i <= sqrt(a); i++){
        if(a%i == 0)    return false;
    }

    return true;
}

int main(){
    ll n;
    cin >> n;
    for(ll i = 2; i <= sqrt(n); i++){
        if(n % i == 0){
            if(!isPrime(i) || !isPrime(n/i)){
                cout << "YES" << endl;
                return 0;
            }
            while(n%i == 0){
                n /= i;
            }
        }
    }

    cout << "NO" << endl;
    return 0;
}