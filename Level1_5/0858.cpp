#include<iostream>
using namespace std;
typedef long long ll;

int main(){
    ll a, b;
    cin >> a >> b;
    ll x = a/b;
    a %= b;
    a *= 10;
    cout << x << ".";
    for(int i = 0; i < 50; i++){
        cout << a/b;
        a %= b;
        a *= 10;
    }
    cout << endl;
    return 0;
}